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

    std::vector<double> GetResult();

    /// Set the delta of the final layer
    /// \param[in] expectedOutput the expected output of the final layer
    /// \warn the values of the final layer must have been set before setting the delta
    void SetDelta(double* expectedOutput);
};