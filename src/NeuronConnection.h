#pragma once

class Neuron;

/// Class that connects 2 layers
class NeuronConnection
{
public:
	/// Constructor
	NeuronConnection(Neuron* neuronInput, Neuron* neuronOutput);

	/// Destructor
	~NeuronConnection() = default;

private:
	/// The weight of the connection (w)
	double mWeight;

	/// The input neuron
	Neuron* mNeuronInput;

	/// The output neuron
	Neuron* mNeuronOutput;

};