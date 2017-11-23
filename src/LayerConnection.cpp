#include <LayerConnection.h>

#include <NeuronConnection.h>
#include <ILayer.h>

LayerConnection::LayerConnection(ILayer* inputLayer, ILayer* outputLayer)
{
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
}