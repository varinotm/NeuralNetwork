#include "LayerFactory.h"

#include "StartLayer.h"
#include "HiddenLayer.h"
#include "FinalLayer.h"

StartLayer* LayerFactory::CreateStartLayer(int nbNeuron)
{
    return new StartLayer(nbNeuron);
}

HiddenLayer* LayerFactory::CreateHiddenLayer(int nbNeuron)
{
    return new HiddenLayer(nbNeuron);
}

FinalLayer* LayerFactory::CreateFinalLayer(int nbNeuron)
{
    return new FinalLayer(nbNeuron);
}