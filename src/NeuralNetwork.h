#pragma once

#include <LayerFactory.h>

#include <vector>

class LayerConnection;
class INormalizerFunction;

class NeuralNetwork
{
public:
    /// Constructor
    NeuralNetwork();

    /// Destructor
    ~NeuralNetwork();

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