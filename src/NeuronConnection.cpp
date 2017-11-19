#include <NeuronConnection.h>

NeuronConnection::NeuronConnection(Neuron* neuronInput, Neuron* neuronOutput)
{
	mNeuronInput = neuronInput;
	mNeuronOutput = neuronOutput;

	mWeight = 0;
}