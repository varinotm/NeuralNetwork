#include "Neuron.h"

Neuron::Neuron()
{
    mValue = 0;
}

Neuron::~Neuron()
{

}

double Neuron::GetValue() const
{
    return mValue;
}

void Neuron::SetValue(double value)
{
    mValue = value;
}