#include "ILayer.h"
#include "Neuron.h"

ILayer::ILayer(int nbNeuron)
{
    for (int i = 0; i < nbNeuron; i++)
    {
        mNeuronList.push_back(new Neuron());
    }
}

ILayer::~ILayer()
{
    for (auto neuron : mNeuronList)
    {
        delete neuron;
        neuron = nullptr;
    }
    mNeuronList.clear();
}

std::vector<Neuron*>& ILayer::GetNeuronList()
{
    return mNeuronList;
}

void ILayer::InitializeBias()
{
    for (auto neuron : mNeuronList)
    {
        neuron->SetBias(0);
    }
}

void ILayer::ResetValue()
{
    for (auto neuron : mNeuronList)
    {
        neuron->SetValue(0);
    }
}

void ILayer::ResetDelta()
{
    for (auto neuron : mNeuronList)
    {
        neuron->SetDelta(0);
    }
}