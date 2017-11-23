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
    // @{
    StartLayer* CreateStartLayer();
    HiddenLayer* CreateHiddenLayer();
    FinalLayer* CreateFinalLayer();
    // @}
};