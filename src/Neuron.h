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

    /// Get the neuron bias (b) 
    /// \return the neuron bias
    double GetBias() const;

    /// Set the neuron bias (b) 
    /// \param[in] bias the new bias of the neuron
    void SetBias(double bias);

    /// Set the neuron value (a) value between 0 and 1
    /// \param[in] value the new value of the neuron
    void SetValue(double value);

private:
    /// Value going from 0 to 1
    double mValue;

    /// The bias to add to the neuron
    double mBias;
};