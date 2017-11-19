#include <HiddenLayer.h>

#include <FinalLayer.h>

HiddenLayer::HiddenLayer()
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