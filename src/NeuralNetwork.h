#pragma once

#include "LayerFactory.h"

#include <vector>

class LayerConnection;
class INormalizerFunction;

class NeuralNetwork
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of neurons peur layer
    NeuralNetwork(std::vector<int> nbNeurons);

    /// Destructor
    ~NeuralNetwork();

    /// Initialize the neural network, setting the bias to 0 and randomizing the weight
    void Initialize();

    /// Initialize the input layer
    /// \param[in] input the input vector containing the initial data from which we
    ///                  want to compute an output
    void SetInputLayer(double* input);

    /// Compute the result of the output layer
    /// an input layer must be set
    void ComputeResult();

private:
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