#pragma once

#include <vector>

class ILayer;
class NeuronConnection;

/// cllas that connects 2 layers together
class LayerConnection
{
public:
	/// Constructor
	LayerConnection(ILayer* inputLayer, ILayer* outputLayer);

	/// Destructor
	~LayerConnection();

private:
	/// The input layer
	ILayer* mInputLayer;

	/// The output layer
	ILayer* mOutputLayer;

	/// All the neuron connections from 2 layers.
	/// For each neurons of the input layer, there will be a connection with all
	/// the neurons of the output layer.
	std::vector<std::vector<NeuronConnection*>> mNeuronConnectionMatrix;
};