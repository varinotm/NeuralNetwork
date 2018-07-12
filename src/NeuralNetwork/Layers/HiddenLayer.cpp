#include "HiddenLayer.h"

#include "FinalLayer.h"

HiddenLayer::HiddenLayer(int nbNeuron) :
ILayer(nbNeuron)
{

}

void HiddenLayer::SetOutputLayer(HiddenLayer* hiddenLayer)
{
    mLayer = hiddenLayer;
}

void HiddenLayer::SetOutputLayer(FinalLayer* finalLayer)
{
    mLayer = finalLayer;
}