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

double NeuronConnection::GetWeight() const
{
    return mWeight;
}

double NeuronConnection::GetSubErrorFactor() const
{
    return mOutputNeuron->GetDelta() * mWeight;
}

void NeuronConnection::UpdateWeight(double learningRate)
{
    SetWeight(
        mWeight + (learningRate * mInputNeuron->GetValue() * mOutputNeuron->GetDelta())
    );
}