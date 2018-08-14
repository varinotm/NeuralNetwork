#include "LayerConnection.h"

#include "NeuralNetwork/Neurons/NeuronConnection.h"
#include "ILayer.h"
#include "Functions/INormalizerFunction.h"

#include "NeuralNetwork/Neurons/Neuron.h"

#include <math.h>

namespace
{
    double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
}

LayerConnection::LayerConnection(ILayer* inputLayer, 
                                 ILayer* outputLayer,
                                 INormalizerFunction* normalizerFunction)
{
    mNormalizerFunction = normalizerFunction;

    mInputLayer = inputLayer;
    mOutputLayer = outputLayer;

    mWeightMatrix = new MatrixD(mOutputLayer->GetNbNeurons(), mInputLayer->GetNbNeurons());
}

LayerConnection::~LayerConnection()
{
    delete mWeightMatrix;
}

void LayerConnection::InitializeWeight()
{
    auto nbOutputNeurons = mOutputLayer->GetNbNeurons();
    auto nbInputNeurons = mInputLayer->GetNbNeurons();
    for (int i = 0; i < nbOutputNeurons; i++)
    {
        for (int j = 0; j < nbInputNeurons; j++)
        {
            (*mWeightMatrix)(i, j) = fRand(-1.0 / sqrt(nbInputNeurons), 1.0 / sqrt(nbInputNeurons));
        }
    }
}

void LayerConnection::ComputeOutputLayer()
{
    mOutputLayer->GetValues()->Multiply(mWeightMatrix, mInputLayer->GetValues());

    mOutputLayer->GetValues()->Add(mOutputLayer->GetBias());
    for (int i = 0; i < mOutputLayer->GetNbNeurons(); i++)
    {
        mOutputLayer->GetValues()->GetMatrix()[i] = mNormalizerFunction->NormalizeValue(mOutputLayer->GetValues()->GetMatrix()[i]);
    }
    
}

void LayerConnection::ComputeInputLayerDelta()
{
    // for every input node
    for (int i = 0; i < mInputLayer->GetNbNeurons(); i++)
    {
        double errorFactor = 0;

        // For every output node
        for (int j = 0; j < mOutputLayer->GetNbNeurons(); j++)
        {
            // output node delta * weight
            errorFactor += (*mOutputLayer->GetDelta())(j, 0) * (*mWeightMatrix)(j,i);
        }
        (*mInputLayer->GetDelta())(i, 0) = (*mInputLayer->GetValues())(i, 0) * ( 1 - (*mInputLayer->GetValues())(i, 0)) * errorFactor;
    }
}

void LayerConnection::UpdateWeightAndBias(double learningRate)
{
    // update the bias
    for (int i = 0; i < mOutputLayer->GetNbNeurons(); i++)
    {
        // New bias = old bias + (learning rate * delta)
        (*mOutputLayer->GetBias())(i, 0) += learningRate * (*mOutputLayer->GetDelta())(i, 0);
    }
    
    // Update the weight
    // new weight = old weight + (learningRate * inputNodeValue * outputNodeDelta)
    auto nbOutputNeurons = mOutputLayer->GetNbNeurons();
    auto mInputNeurons = mInputLayer->GetNbNeurons();
    for (int i = 0; i < nbOutputNeurons; i++)
    {
        for (int j = 0; j < mInputNeurons; j++)
        {
            (*mWeightMatrix)(i, j) += learningRate * (*mInputLayer->GetValues())(j, 0) * (*mOutputLayer->GetDelta())(i, 0);
        }
    }
}

MatrixD* LayerConnection::GetWeightMatrix()
{
    return mWeightMatrix;
}