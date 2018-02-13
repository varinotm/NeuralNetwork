#pragma once

#include "LayerFactory.h"

#include <vector>

class LayerConnection;
class INormalizerFunction;

class NeuralNetwork
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of neurons per layer
    NeuralNetwork(std::vector<int> nbNeurons);

    /// Destructor
    ~NeuralNetwork();

    /// Initialize the neural network, setting the size of each layers
    /// \param[in] nbNeurons the number of neurons for each layer
    void Initialize(std::vector<int> nbNeurons);

    /// Initialize the neural network, setting the bias to 0 and randomizing the weight
    void InitializeBiasAndWeights();

    /// Initialize the input layer
    /// \param[in] input the input vector containing the initial data from which we
    ///                  want to compute an output
    void SetInputLayer(double* input);

    /// Compute the delta of all neurons given an expected output
    /// \param[in] expectedOutput the expected output
    /// \warn a result should be computed before giving an expected output
    void ComputeDelta(double* expectedOutput);

    /// Update the weight and bias of the neural network
    /// \param[in] learningRate the learning rate of the neural network
    void UpdateWeightAndBias(double learningRate);

    /// Reset the values of all neurons and their delta
    void ResetValueAndDelta();

    /// Compute the result of the output layer
    /// \warn an input layer must be set
    void ComputeResult();

    /// Get the result of the output layer
    std::vector<double> GetResult();

    /// Get the output size
    /// \return the number of nodes in the last layer
    unsigned int GetOutputSize();

    /// Save the current neural network to the specified path
    /// \param[in] path the path to the file containing all bias and weight of the neural network.
    void Save(const std::string& path);

    /// Load the wanted neural network
    /// \param[in] path the path to load the file containing all bias and weight and build
    ///                 the neural network.
    void Load(const std::string& path);

private:

    /// Clear the neural network, resetting everything
    void Clear();

    /// The layer factory
    LayerFactory mLayerFactory;

    /// The layers
    // @{
    StartLayer* mStartLayer;
    std::vector<HiddenLayer*> mHiddenLayerList;
    FinalLayer* mFinalLayer;
    // @}

    /// The list of connection between the layers
    std::vector<LayerConnection*> mLayerConnectionList;

    INormalizerFunction* mNormalizerFunction;
};