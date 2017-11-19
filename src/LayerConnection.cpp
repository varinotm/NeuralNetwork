#include <LayerConnection.h>

#include <NeuronConnection.h>
#include <ILayer.h>

LayerConnection::LayerConnection(ILayer* inputLayer, ILayer* outputLayer)
{
    mInputLayer = inputLayer;

    mOutputLayer = outputLayer;

    for (auto inputNeuron : mInputLayer->GetNeuronList())
    {
        std::vector<NeuronConnection*> neuronConnectionList;
        for (auto outputNeuron : mOutputLayer->GetNeuronList())
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