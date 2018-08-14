#pragma once

class ILayer;
class INormalizerFunction;
class MatrixD;

/// class that connects 2 layers together
class LayerConnection
{
public:
    /// Constructor
    /// \param[in] inputLayer the input layer
    /// \param[in] outputLayer the output layer
    /// \param[in] normalizerFunction the normalizer function for the output values
    LayerConnection(ILayer* inputLayer,
                    ILayer* outputLayer,
                    INormalizerFunction* normalizerFunction);

    /// Destructor
    ~LayerConnection();

    /// Compute the output of a layer connection
    /// Will update the value of every output node
    void ComputeOutputLayer();

    /// Compute the delta value of the input layer (from the delta value of the output layer)
    /// Will update the delta of every input node
    void ComputeInputLayerDelta();

    /// Update the weight and bias of the neural network
    /// \param[in] learningRate the learning rate of the neural network
    void UpdateWeightAndBias(double learningRate);

    /// Initialize the value of the weight and bias
    void InitializeWeight();

    /// Get the weight matrix
    /// \return the weight matrix
    MatrixD* GetWeightMatrix();

private:
    /// The input layer
    ILayer* mInputLayer;

    /// The output layer
    ILayer* mOutputLayer;

    /// The normalizer function, to transform an output node to a value between 0 and 1
    INormalizerFunction* mNormalizerFunction;

    /// the weight matrix
    MatrixD * mWeightMatrix;
};