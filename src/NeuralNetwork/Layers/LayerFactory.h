#pragma once

class StartLayer;
class HiddenLayer;
class FinalLayer;
/// Factory class to create layers
class LayerFactory
{
public:
    /// Constructor
    LayerFactory() = default;

    /// Destructor
    ~LayerFactory() = default;
    
    /// Create a layer
    /// \param[in] nbNeuron the number of desired neuron for the layer
    // @{
    StartLayer* CreateStartLayer(int nbNeuron);
    HiddenLayer* CreateHiddenLayer(int nbNeuron);
    FinalLayer* CreateFinalLayer(int nbNeuron);
    // @}
};