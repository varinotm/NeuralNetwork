#pragma once

#include <vector>

class ILayer;
class INormalizerFunction;
class NeuronConnection;

/// cllas that connects 2 layers together
class LayerConnection
{
public:
    /// Constructor
    /// \param[in] inputLayer the input layer
    /// \param[in] outputLayer the output layer
    /// \param[in] normalizerFunction the normalizer function for the output values
    LayerConnection(ILayer* inputLayer,
                    ILayer* outputLayer,
                    INormalizerFunction* normalizerFunction);

    /// Destructor
    ~LayerConnection();

    /// Compute the output of a layer connection
    /// Will update the value of every output node
    void ComputeOutputLayer();

    /// Compute the delta value of the input layer (from the delta value of the output layer)
    /// Will update the delta of every input node
    void ComputeInputLayerDelta();

    /// Update the weight and bias of the neural network
    /// \param[in] learningRate the learning rate of the neural network
    void UpdateWeightAndBias(double learningRate);

    /// Initialize the value of the weight and bias
    void InitializeWeight();

    /// Get the neuron connection matrix of a layer connection
    /// \return the neuron connection matrix
    std::vector<std::vector<NeuronConnection*>> GetNeuronConnectionMatrix() const;

private:
    /// The input layer
    ILayer* mInputLayer;

    /// The output layer
    ILayer* mOutputLayer;

    /// \todo struct with neuronconnection and bias????
    /// \todo find alternative data structure (one where it is easy to iterate through rows or columns)
    /// All the neuron connections from 2 layers.
    /// Each neuron of an output layer is dependent on the value on all input neuron
    std::vector<std::vector<NeuronConnection*>> mNeuronConnectionMatrix;

    /// The normalizer function, to transform an output node to a value between 0 and 1
    INormalizerFunction* mNormalizerFunction;
};