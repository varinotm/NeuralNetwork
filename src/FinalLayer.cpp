#include "FinalLayer.h"

#include "Neuron.h"

FinalLayer::FinalLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}

std::vector<double> FinalLayer::GetResult()
{
    std::vector<double> result;
    for (int i = 0; i < mNeuronList.size(); i++)
    {
        result.push_back(mNeuronList[i]->GetValue());
    }

    return result;
}

void FinalLayer::SetDelta(double* expectedOutput)
{
    for (int i = 0; i < mNeuronList.size(); i++)
    {
        auto neuron = mNeuronList[i];
        neuron->SetDelta(
            neuron->GetValue() *
            (1-neuron->GetValue()) *
            (expectedOutput[i] - neuron->GetValue()) // Error factor : expectedvalue - currentValue
        );
    }
}