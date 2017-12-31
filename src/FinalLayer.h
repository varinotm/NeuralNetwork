#pragma once

#include "ILayer.h"

/// The final layer : should contain only a list of neurons with 0 or 1
/// values
class FinalLayer : public ILayer
{
public:
    /// Constructor
    /// \param[in] nbNeuron the number of desired neuron for the layer
    FinalLayer(int nbNeuron);

    /// Destructor
    ~FinalLayer() = default;
};