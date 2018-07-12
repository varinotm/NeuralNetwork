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

    /// Set the weight of the connection
    void SetWeight(double weight);

    /// Get the weight of a connection between 2 neurons
    /// \return the weight of the connection
    double GetWeight() const;

    /// Update the weight during a training of the neural network
    /// \param[in] learningRate the learning rate
    void UpdateWeight(double learningRate);

    /// Calculate and return the error factor of the current connection
    /// \return the error factor of the current connection
    double GetSubErrorFactor() const;

private:
    /// The weight of the connection (w)
    double mWeight;

    /// The input neuron
    Neuron* mInputNeuron;

    /// The output neuron
    Neuron* mOutputNeuron;
};