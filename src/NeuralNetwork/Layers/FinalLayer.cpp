#include "FinalLayer.h"

#include "NeuralNetwork/Neurons/Neuron.h"

FinalLayer::FinalLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}


void FinalLayer::SetDelta(double* expectedOutput)
{
    for (int i = 0; i < mNbNeurons; i++)
    {
        double neuronValue = (*mNeuronValues)(i, 0);
        // Error factor : expectedvalue - currentValue
        double errorFactor = expectedOutput[i] - neuronValue;

        // new delta : mDelta = mValue * (1 - mValue) * errorFactor;
        (*mNeuronDelta)(i, 0) = neuronValue * (1 - neuronValue) * errorFactor;
    }
}