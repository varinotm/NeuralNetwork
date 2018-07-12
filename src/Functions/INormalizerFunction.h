#pragma once

/// interface to normalize value
class INormalizerFunction
{
public:
    ///Destructor
    ~INormalizerFunction() = default;

    /// Normalize a given value so that the result is between 0 and 1
    /// \param[in] value a value
    /// \return a value between 0 and 1
    virtual double NormalizeValue(double value) = 0;

protected:
    /// Constructor
    INormalizerFunction() = default;
};