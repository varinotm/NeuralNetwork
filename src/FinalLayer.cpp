#include "FinalLayer.h"

#include "Neuron.h"

FinalLayer::FinalLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}

std::vector<double> FinalLayer::GetResult()
{
    std::vector<double> result;
    for (unsigned int i = 0; i < mNeuronList.size(); i++)
    {
        result.push_back(mNeuronList[i]->GetValue());
    }

    return result;
}

void FinalLayer::SetDelta(double* expectedOutput)
{
    for (unsigned int i = 0; i < mNeuronList.size(); i++)
    {
        auto neuron = mNeuronList[i];

        // Error factor : expectedvalue - currentValue
        neuron->ComputeDelta(expectedOutput[i] - neuron->GetValue());
    }
}