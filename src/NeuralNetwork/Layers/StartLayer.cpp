#include "StartLayer.h"

#include "HiddenLayer.h"
#include "FinalLayer.h"

#include "../Neurons/Neuron.h"

StartLayer::StartLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}

void StartLayer::SetInputNeurons(double* input)
{
    for (unsigned int i = 0; i < mNeuronList.size(); i++)
    {
        mNeuronList[i]->SetValue(input[i]);
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