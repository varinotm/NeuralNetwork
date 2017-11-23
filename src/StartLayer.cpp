#include <StartLayer.h>

#include <HiddenLayer.h>
#include <FinalLayer.h>

StartLayer::StartLayer()
{

}

void StartLayer::SetOutputLayer(HiddenLayer* hiddenLayer)
{
    mOutputLayer = hiddenLayer;
}

void StartLayer::SetOutputLayer(FinalLayer* finalLayer)
{
    mOutputLayer = finalLayer;
}