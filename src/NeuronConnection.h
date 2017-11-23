#pragma once

class Neuron;

/// Class that connects 2 neurons
class NeuronConnection
{
public:
    /// Constructor
    NeuronConnection(Neuron* inputNeuron, Neuron* outputNeuron);

    /// Destructor
    ~NeuronConnection() = default;

    /// Compute the value of an output neuron
    /// outputNodeValue = (inputNodeValue1 * weight1) + (inputNodeValue2 * weight2) + ...
    void ComputeOutputNeuron();

private:
    /// The weight of the connection (w)
    double mWeight;

    /// The input neuron
    Neuron* mInputNeuron;

    /// The output neuron
    Neuron* mOutputNeuron;
};