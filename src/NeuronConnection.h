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

private:
    /// The weight of the connection (w)
    double mWeight;

    /// The input neuron
    Neuron* mInputNeuron;

    /// The output neuron
    Neuron* mOutputNeuron;
};