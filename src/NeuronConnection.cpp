#include <NeuronConnection.h>

NeuronConnection::NeuronConnection(Neuron* inputNeuron, Neuron* outputNeuron)
{
    mInputNeuron = inputNeuron;
    mOutputNeuron = outputNeuron;

    mWeight = 0;
}