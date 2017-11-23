#include "LayerFactory.h"

#include "StartLayer.h"
#include "HiddenLayer.h"
#include "FinalLayer.h"

StartLayer* LayerFactory::CreateStartLayer()
{
    return new StartLayer();
}

HiddenLayer* LayerFactory::CreateHiddenLayer()
{
    return new HiddenLayer();
}

FinalLayer* LayerFactory::CreateFinalLayer()
{
    return new FinalLayer();
}