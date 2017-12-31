#include "NeuronConnection.h"

#include "Neuron.h"

NeuronConnection::NeuronConnection(Neuron* inputNeuron, Neuron* outputNeuron)
{
    mInputNeuron = inputNeuron;
    mOutputNeuron = outputNeuron;

    mWeight = 0;
}

void NeuronConnection::ComputeOutputNeuron()
{
    mOutputNeuron->SetValue(
        mOutputNeuron->GetValue() +
        (mInputNeuron->GetValue() *
        mWeight));
}

void NeuronConnection::SetWeight(double weight)
{
    mWeight = weight;
}
