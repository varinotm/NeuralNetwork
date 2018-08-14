#pragma once

class MatrixD;

/// Layer class containing a list of neurons
class ILayer
{
public:
    /// Constructor
    /// \param[in] nbNeurons the number of desired neuron for the layer
    ILayer(int nbNeurons);

    /// Destructor
    ~ILayer();

    /// Initialize the bias to 0 of all neurons in the layer
    void InitializeBias();

    /// Reset all neurons values to 0
    void ResetValue();

    /// Reset all neurons deltas to 0
    void ResetDelta();

    /// Return the number of neurons in the layer
    int GetNbNeurons() const;

    /// Return the neuron values of the layer
    MatrixD* GetValues();

    /// Return the neuron bias of the layer
    MatrixD* GetBias();

    /// Return the neuron delta of the layer
    MatrixD* GetDelta();

protected:

    int mNbNeurons;
    MatrixD* mNeuronValues;
    MatrixD* mNeuronBias;
    MatrixD* mNeuronDelta;
};