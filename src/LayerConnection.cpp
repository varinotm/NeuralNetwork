#include "LayerConnection.h"

#include "NeuronConnection.h"
#include "ILayer.h"
#include "INormalizerFunction.h"

#include "Neuron.h"

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

    // Apply normalizer function so that the output node value is a value between 0 and 1
    for (auto neuron : mOutputLayer->GetNeuronList())
    {
        neuron->SetValue(mNormalizerFunction->NormalizeValue(neuron->GetValue()));
    }
}