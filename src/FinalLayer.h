#pragma once

#include <ILayer.h>

/// The final layer : should contain only a list of neurons with 0 or 1
/// values
class FinalLayer : public ILayer
{
public:
    /// Constructor
    FinalLayer() = default;

    /// Destructor
    ~FinalLayer() = default;
};