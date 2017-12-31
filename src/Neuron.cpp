#include "Neuron.h"

Neuron::Neuron()
{
    mValue = 0;
    mBias = 0;
}

Neuron::~Neuron()
{

}

double Neuron::GetValue() const
{
    return mValue;
}

double Neuron::GetBias() const
{
    return mValue;
}

void Neuron::SetValue(double value)
{
    mValue = value;
}

void Neuron::SetBias(double bias)
{
    mBias = bias;
}