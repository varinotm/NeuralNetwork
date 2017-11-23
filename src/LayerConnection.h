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

    /// Compute the output of a layer connection
    /// Will update the value of every output node
    void ComputeOutputLayer();

private:
    /// The input layer
    ILayer* mInputLayer;

    /// The output layer
    ILayer* mOutputLayer;

    /// All the neuron connections from 2 layers.
    /// Each neuron of an output layer is dependent on the value on all input neuron
    std::vector<std::vector<NeuronConnection*>> mNeuronConnectionMatrix;
};