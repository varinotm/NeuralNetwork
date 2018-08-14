#include "StartLayer.h"

#include "HiddenLayer.h"
#include "FinalLayer.h"

#include "NeuralNetwork\Neurons\Neuron.h"

StartLayer::StartLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}

void StartLayer::SetInputNeurons(double* input)
{
    for (int i = 0; i < mNbNeurons; i++)
    {
        (*mNeuronValues)(i, 0) = input[i];
    }
}

void StartLayer::SetOutputLayer(HiddenLayer* hiddenLayer)
{
    mOutputLayer = hiddenLayer;
}

void StartLayer::SetOutputLayer(FinalLayer* finalLayer)
{
    mOutputLayer = finalLayer;
}