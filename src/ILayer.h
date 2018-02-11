#pragma once

#include <vector>

class Neuron;

/// Layer class containing a list of neurons
class ILayer
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of desired neuron for the layer
    ILayer(int nbNeuron);

    /// Destructor
    ~ILayer();

    /// Get the list of neuron of the layer
    std::vector<Neuron*>& GetNeuronList();

    /// Initialize the bias to 0 of all neurons in the layer
    void InitializeBias();

protected:
    /// The layer contains a list of Neuron
    std::vector<Neuron*> mNeuronList;
};