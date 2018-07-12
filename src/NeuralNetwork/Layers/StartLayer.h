#pragma once

#include "ILayer.h"

class HiddenLayer;
class FinalLayer;

/// Layer class containing a list of neurons
class StartLayer : public ILayer
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of desired neuron for the layer
    StartLayer(int nbNeuron);

    /// Destructor
    ~StartLayer() = default;

    /// Set the input neurons value
    /// \param[in] input the neuron values for the start layer
    void SetInputNeurons(double* input);

    /// Set the output Layer. Will overwrite any previous output layer
    //@{
    void SetOutputLayer(HiddenLayer* hiddenLayer);
    void SetOutputLayer(FinalLayer* finalLayer);
    //@}

private:
    ILayer* mOutputLayer;
};