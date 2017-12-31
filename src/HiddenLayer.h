#pragma once

#include "ILayer.h"

class FinalLayer;

/// Layer class containing a list of neurons
class HiddenLayer : public ILayer
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of desired neuron for the layer
    HiddenLayer(int nbNeuron);

    /// Destructor
    ~HiddenLayer() = default;

    /// Set the output Layer. Will overwrite any previous output layer
    //@{
    void SetOutputLayer(HiddenLayer* hiddenLayer);
    void SetOutputLayer(FinalLayer* finalLayer);
    //@}

private:
    ILayer* mLayer;
};