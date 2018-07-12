#include "Neuron.h"

Neuron::Neuron()
{
    mValue = 0;
    mBias = 0;
    mDelta = 0;
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
    return mBias;
}

double Neuron::GetDelta() const
{
    return mDelta;
}

void Neuron::SetValue(double value)
{
    mValue = value;
}

void Neuron::SetBias(double bias)
{
    mBias = bias;
}

void Neuron::SetDelta(double delta)
{
    mDelta = delta;
}

void Neuron::ComputeDelta(double errorFactor)
{
    mDelta = mValue * (1 - mValue) * errorFactor;
}