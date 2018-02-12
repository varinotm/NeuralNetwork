#include "LayerConnection.h"

#include "NeuronConnection.h"
#include "ILayer.h"
#include "INormalizerFunction.h"

#include "Neuron.h"

#include <math.h>

namespace
{
    double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
}

LayerConnection::LayerConnection(ILayer* inputLayer, 
                                 ILayer* outputLayer,
                                 INormalizerFunction* normalizerFunction)
{
    mNormalizerFunction = normalizerFunction;

    mInputLayer = inputLayer;
    mOutputLayer = outputLayer;

    for (auto outputNeuron : mOutputLayer->GetNeuronList())
    {
        std::vector<NeuronConnection*> neuronConnectionList;
        for (auto inputNeuron : mInputLayer->GetNeuronList())
        {
            neuronConnectionList.push_back(new NeuronConnection(inputNeuron, outputNeuron));
        }
        mNeuronConnectionMatrix.push_back(neuronConnectionList);
    }
}

LayerConnection::~LayerConnection()
{
    for (auto& neuronConnectionList : mNeuronConnectionMatrix)
    {
        for (auto neuronConnection : neuronConnectionList)
        {
            delete neuronConnection;
            neuronConnection = nullptr;
        }
        neuronConnectionList.clear();
    }
    mNeuronConnectionMatrix.clear();
}

void LayerConnection::InitializeWeight()
{
    // For every output node
    for (auto neuronConnectionList : mNeuronConnectionMatrix)
    {
        // For every connection of an output node
        for (auto neuronConnection : neuronConnectionList)
        {
            auto nbInputNeuron = neuronConnectionList.size();
            neuronConnection->SetWeight(fRand(-1/sqrt(nbInputNeuron),
                                               1/sqrt(nbInputNeuron)));
        }
    }
}

void LayerConnection::ComputeOutputLayer()
{
    // For every output node
    for (auto neuronConnectionList : mNeuronConnectionMatrix)
    {
        // For every connection of an output node
        for (auto neuronConnection : neuronConnectionList)
        {
            neuronConnection->ComputeOutputNeuron();
        }
    }

    // We add the bias to each output node
    for (auto neuron : mOutputLayer->GetNeuronList())
    {
        neuron->SetValue(neuron->GetValue() + neuron->GetBias());
    }

    // Apply normalizer function so that the output node value is a value between 0 and 1
    for (auto neuron : mOutputLayer->GetNeuronList())
    {
        neuron->SetValue(mNormalizerFunction->NormalizeValue(neuron->GetValue()));
    }
}

void LayerConnection::ComputeInputLayerDelta()
{
    // for every input node
    for (unsigned int i = 0; i < mInputLayer->GetNeuronList().size(); i++)
    {
        double errorFactor = 0;

        // For every output node
        for (unsigned int j = 0; j < mOutputLayer->GetNeuronList().size(); j++)
        {
            errorFactor += mNeuronConnectionMatrix[j][i]->GetSubErrorFactor();
        }
        mInputLayer->GetNeuronList()[i]->ComputeDelta(errorFactor);
    }
}

void LayerConnection::UpdateWeightAndBias(double learningRate)
{
    // Update the bias
    for (auto outputNeuron : mOutputLayer->GetNeuronList())
    {
        // New bias = old bias * (learning rate * delta)
        outputNeuron->SetBias(outputNeuron->GetBias() + (learningRate * outputNeuron->GetDelta()));
    }

    // Update the weight
    // For every output node
    for (auto neuronConnectionList : mNeuronConnectionMatrix)
    {
        // For every connection of an output node
        for (auto neuronConnection : neuronConnectionList)
        {
            neuronConnection->UpdateWeight(learningRate);
        }
    }
}

std::vector<std::vector<NeuronConnection*>> LayerConnection::GetNeuronConnectionMatrix() const
{
    return mNeuronConnectionMatrix;
}