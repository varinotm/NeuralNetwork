#include "ILayer.h"
#include <DataStructure\MatrixD.h>

ILayer::ILayer(int nbNeurons)
{
    mNbNeurons = nbNeurons;
    mNeuronValues = new MatrixD(nbNeurons, 1);
    mNeuronBias = new MatrixD(nbNeurons, 1);
    mNeuronDelta = new MatrixD(nbNeurons, 1);

}

ILayer::~ILayer()
{
    delete mNeuronValues;
    delete mNeuronBias;
    delete mNeuronDelta;
}

void ILayer::InitializeBias()
{
    mNeuronBias->Reset();
}

void ILayer::ResetValue()
{
    mNeuronValues->Reset();
}

void ILayer::ResetDelta()
{
    mNeuronDelta->Reset();
}

int ILayer::GetNbNeurons() const
{
    return mNbNeurons;
}

MatrixD* ILayer::GetValues()
{
    return mNeuronValues;
}

MatrixD* ILayer::GetBias()
{
    return mNeuronBias;
}

MatrixD* ILayer::GetDelta()
{
    return mNeuronDelta;
}