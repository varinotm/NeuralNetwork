#include "NeuralNetwork.h"

#include "Layers/StartLayer.h"
#include "Layers/HiddenLayer.h"
#include "Layers/FinalLayer.h"

#include "Layers/LayerConnection.h"
#include "Functions/SigmoidNormalizerFunction.h"
#include "DataStructure\MatrixD.h"

#include <sstream>
#include <fstream>

NeuralNetwork::NeuralNetwork(std::vector<int> nbNeurons)
{
    Initialize(nbNeurons);
}

NeuralNetwork::~NeuralNetwork()
{
    Clear();
}

void NeuralNetwork::Initialize(std::vector<int> nbNeurons)
{
    // Normalizer function
    mNormalizerFunction = new SigmoidNormalizerFunction();

    // Initialize layers
    mStartLayer = mLayerFactory.CreateStartLayer(nbNeurons[0]);

    for (unsigned int i = 1; i < nbNeurons.size() - 1; i++)
    {
        mHiddenLayerList.push_back(
            mLayerFactory.CreateHiddenLayer(nbNeurons[i]));
    }

    mFinalLayer = mLayerFactory.CreateFinalLayer(
        nbNeurons[nbNeurons.size() - 1]);

    // Create connections
    if (mHiddenLayerList.size() == 0)
    {
        mLayerConnectionList.push_back(new LayerConnection(mStartLayer,
                                                           mFinalLayer,
                                                           mNormalizerFunction));
    }
    else
    {
        mLayerConnectionList.push_back(new LayerConnection(mStartLayer,
                                                           mHiddenLayerList[0],
                                                           mNormalizerFunction));
        for (unsigned int i = 0; i < mHiddenLayerList.size(); i++)
        {
            if (i + 1 < mHiddenLayerList.size())
            {
                mLayerConnectionList.push_back(new LayerConnection(mHiddenLayerList[i],
                                                                   mHiddenLayerList[i + 1],
                                                                   mNormalizerFunction));
            }
            else
            {
                mLayerConnectionList.push_back(new LayerConnection(mHiddenLayerList[i],
                                                                   mFinalLayer,
                                                                   mNormalizerFunction));
            }
        }
    }
}

void NeuralNetwork::InitializeBiasAndWeights()
{
    // Reset the bias of every neuron to 0
    mStartLayer->InitializeBias();
    for (auto hiddenLayer : mHiddenLayerList)
    {
        hiddenLayer->InitializeBias();
    }
    mFinalLayer->InitializeBias();

    // For every layer connection from left to right, initialize the weight
    for (auto layerConnection : mLayerConnectionList)
    {
        layerConnection->InitializeWeight();
    }
}

void NeuralNetwork::ResetValueAndDelta()
{
    mStartLayer->ResetValue();
    mStartLayer->ResetDelta();
    for (auto hiddenLayer : mHiddenLayerList)
    {
        hiddenLayer->ResetValue();
        hiddenLayer->ResetDelta();
    }
    mFinalLayer->ResetValue();
    mFinalLayer->ResetDelta();
}

void NeuralNetwork::ComputeResult()
{
    // For every layer connection from left to right
    for (auto layerConnection : mLayerConnectionList)
    {
        layerConnection->ComputeOutputLayer();
    }
}

int NeuralNetwork::GetOutputSize()
{
    return mFinalLayer->GetNbNeurons();
}

double* NeuralNetwork::GetResult()
{
    return mFinalLayer->GetValues()->GetMatrix();
}

void NeuralNetwork::SetInputLayer(double* input)
{
    mStartLayer->SetInputNeurons(input);
}

void NeuralNetwork::ComputeDelta(double* expectedOutput)
{
    mFinalLayer->SetDelta(expectedOutput);

    /// \todo compute delta of all neurons
    /// We start fromm the last layer to the first layer in the delta computation
    for (size_t i = mLayerConnectionList.size()-1; i > 0; i--)
    {
        auto layerConnection = mLayerConnectionList[i];
        layerConnection->ComputeInputLayerDelta();
    }
}

void NeuralNetwork::UpdateWeightAndBias(double learningRate)
{
    for (auto layerConnection : mLayerConnectionList)
    {
        layerConnection->UpdateWeightAndBias(learningRate);
    }
}

void NeuralNetwork::Clear()
{
    for (auto layerConnection : mLayerConnectionList)
    {
        delete layerConnection;
        layerConnection = nullptr;
    }
    mLayerConnectionList.clear();

    delete mNormalizerFunction;
    mNormalizerFunction = nullptr;

    delete mStartLayer;
    mStartLayer = nullptr;

    for (auto hiddenLayer : mHiddenLayerList)
    {
        delete hiddenLayer;
        hiddenLayer = nullptr;
    }
    mHiddenLayerList.clear();

    delete mFinalLayer;
    mFinalLayer = nullptr;
}

void NeuralNetwork::Save(const std::string& path)
{
    std::ofstream myfile;
    myfile.open(path);
    
    /// First line will save the number of neurons at each layer
    myfile << mStartLayer->GetNbNeurons() << " ";

    for (auto hiddenLayer : mHiddenLayerList)
    {
        myfile << hiddenLayer->GetNbNeurons() << " ";
    }

    myfile << mFinalLayer->GetNbNeurons() << "\n";

    /// Next we save all bias, layer per layer, neuron per neuron
    for (int i = 0; i< mStartLayer->GetNbNeurons(); i++)
    {
        // Should be all 0, since its the start layer
        myfile << (*mStartLayer->GetBias())(i, 0) << "\n";
    }

    for (auto hiddenLayer : mHiddenLayerList)
    {
        for (int i = 0; i< hiddenLayer->GetNbNeurons(); i++)
        {
            myfile << (*hiddenLayer->GetBias())(i, 0) << "\n";
        }
    }
    
    for (int i = 0; i< mFinalLayer->GetNbNeurons(); i++)
    {
        myfile << (*mFinalLayer->GetBias())(i, 0) << "\n";
    }

    // Finally, we save the value of each weight
    for (auto layerConnection : mLayerConnectionList)
    {
        auto weightMatrix = layerConnection->GetWeightMatrix();
        for (int i = 0; i < weightMatrix->GetNbRows(); i++)
        {
            for (int j = 0; j < weightMatrix->GetNbCols(); j++)
            {
                myfile << (*weightMatrix)(i, j) << "\n";
            }
        }     
    }

    myfile.close();
}

void NeuralNetwork::Load(const std::string& path)
{
    /// \todo We may want to create a duplicate neural network 
    /// and copy to the original only if the loading is successful

    /// Clear the current neural network
    Clear();

    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        std::string line;

        /// Read the first line to initialize the neural network size
        getline(myfile, line);

        std::vector<int> nbNeurons;
        std::istringstream is(line);
        int layerNeurons;
        double value;

        while (is >> layerNeurons)
        {
            nbNeurons.push_back(layerNeurons);
        }

        Initialize(nbNeurons);

        /// Set the bias of each neuron
        for (int i = 0; i < mStartLayer->GetNbNeurons(); i++)
        {
            myfile >> value;
            (*mStartLayer->GetBias())(i, 0) = value;
        }

        for (auto hiddenLayer : mHiddenLayerList)
        {
            for (int i = 0; i < hiddenLayer->GetNbNeurons(); i++)
            {
                myfile >> value;
                (*hiddenLayer->GetBias())(i, 0) = value;
            }
        }

        for (int i = 0; i < mFinalLayer->GetNbNeurons(); i++)
        {
            myfile >> value;
            (*mFinalLayer->GetBias())(i, 0) = value;
        }

        // Set the weight of each connection
        for (auto layerConnection : mLayerConnectionList)
        {
            auto weightMatrix = layerConnection->GetWeightMatrix();
            for (int i = 0; i < weightMatrix->GetNbRows(); i++)
            {
                for (int j = 0; j < weightMatrix->GetNbCols(); j++)
                {
                    myfile >> value;
                    (*weightMatrix)(i, j) = value;
                }
            }
        }

        myfile.close();
    }    
}