#include "NeuralNetwork.h"

#include "StartLayer.h"
#include "HiddenLayer.h"
#include "FinalLayer.h"

#include "LayerConnection.h"
#include "SigmoidNormalizerFunction.h"

#include "Neuron.h"
#include "NeuronConnection.h"
#include <fstream>

NeuralNetwork::NeuralNetwork(std::vector<int> nbNeurons)
{
    // Test : 1 start layer, 2 hidden layers, 1 output layer

    // Initialize layers
    mStartLayer = mLayerFactory.CreateStartLayer(nbNeurons[0]);

    for (unsigned int i = 1; i < nbNeurons.size()-1; i++)
    {
        mHiddenLayerList.push_back(mLayerFactory.CreateHiddenLayer(nbNeurons[i]));
    }

    mFinalLayer = mLayerFactory.CreateFinalLayer(nbNeurons[nbNeurons.size()-1]);

    // Normalizer function
    mNormalizerFunction = new SigmoidNormalizerFunction();

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

NeuralNetwork::~NeuralNetwork()
{
    Clear();
}

void NeuralNetwork::Initialize()
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

void NeuralNetwork::ComputeResult()
{
    // For every layer connection from left to right
    for (auto layerConnection : mLayerConnectionList)
    {
        layerConnection->ComputeOutputLayer();
    }
}

void NeuralNetwork::SetInputLayer(double* input)
{
    mStartLayer->SetInputNeurons(input);
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
    myfile << mStartLayer->GetNeuronList().size() << " ";

    for (auto hiddenLayer : mHiddenLayerList)
    {
        myfile << hiddenLayer->GetNeuronList().size() << " ";
    }

    myfile << mFinalLayer->GetNeuronList().size() << "\n";

    /// Next we save all bias, layer per layer, neuron per neuron
    for (auto neuron : mStartLayer->GetNeuronList())
    {
        // Should be all 0, since its the start layer
        myfile << neuron->GetBias() << "\n";
    }

    for (auto hiddenLayer : mHiddenLayerList)
    {
        for (auto neuron : hiddenLayer->GetNeuronList())
        {
            myfile << neuron->GetBias() << "\n";
        }
    }
    
    for (auto neuron : mFinalLayer->GetNeuronList())
    {
        myfile << neuron->GetBias() << "\n";
    }

    // Finally, we save the value of each weight
    for (auto layerConnection : mLayerConnectionList)
    {
        for (auto neuronConnectionList : layerConnection->GetNeuronConnectionMatrix())
        {
            for (auto neuronConnection : neuronConnectionList)
            {
                myfile << neuronConnection->GetWeight() << "\n";
            }
        }        
    }

    myfile.close();
}

void NeuralNetwork::Load(const std::string& path)
{

}