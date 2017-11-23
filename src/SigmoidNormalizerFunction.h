#pragma once

#include "INormalizerFunction.h"

/// Layer class containing a list of neurons
class SigmoidNormalizerFunction : public INormalizerFunction
{
public:
    SigmoidNormalizerFunction() = default;

    ///Destructor
    ~SigmoidNormalizerFunction() = default;

    /// Normalize a given value so that the result is between 0 and 1
    /// \param[in] value a value
    /// \return a value between 0 and 1
    virtual double NormalizeValue(double value) override;
};