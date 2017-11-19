#include <ILayer.h>
#include <Neuron.h>

ILayer::ILayer()
{

}

ILayer::~ILayer()
{
	for (auto neuron : mNeuronList)
	{
		delete neuron;
		neuron = nullptr;
	}
}