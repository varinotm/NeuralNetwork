#pragma once


/// Neuron in a layer. Its value goes from 0 to 1
class Neuron
{
public:
    /// Constructor
    Neuron();

    /// Destructor
    ~Neuron();

    /// Get the neuron value (a) Value between 0 and 1
    /// \return the neuron value
    double GetValue() const;

    /// Set the neuron value (a) value between 0 and 1
    /// \param[in] value the new value of the neuron
    void SetValue(double value);

private:
    /// Value going from 0 to 1
    double mValue;


};