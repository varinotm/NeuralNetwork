#pragma once

#include <vector>

class Neuron;

/// Layer class containing a list of neurons
class ILayer
{
public:
    /// Constructor
    ILayer(int nbNeuron = 10);

    /// Destructor
    ~ILayer();

    /// Get the list of neuron of the layer
    std::vector<Neuron*> GetNeuronList();

private:
    std::vector<Neuron*> mNeuronList;
};