#include <StartLayer.h>

#include <HiddenLayer.h>
#include <FinalLayer.h>

StartLayer::StartLayer()
{

}

void StartLayer::SetOutputLayer(HiddenLayer* hiddenLayer)
{
    mLayer = hiddenLayer;
}

void StartLayer::SetOutputLayer(FinalLayer* finalLayer)
{
    mLayer = finalLayer;
}