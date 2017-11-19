#include <NeuralNetwork.h>

#include <StartLayer.h>
#include <HiddenLayer.h>
#include <FinalLayer.h>

NeuralNetwork::NeuralNetwork()
{
	// Test : 1 start layer, 2 hidden layers, 1 output layer

	// Initialize layers
	mStartLayer = mLayerFactory.CreateStartLayer();

	mHiddenLayerList.push_back(mLayerFactory.CreateHiddenLayer());
	mHiddenLayerList.push_back(mLayerFactory.CreateHiddenLayer());

	mFinalLayer = mLayerFactory.CreateFinalLayer();

	// Create connections
	mStartLayer->SetOutputLayer(mHiddenLayerList[0]);

	mHiddenLayerList[0]->SetOutputLayer(mHiddenLayerList[1]);
	mHiddenLayerList[1]->SetOutputLayer(mFinalLayer);
}

NeuralNetwork::~NeuralNetwork()
{
	delete mStartLayer;
	mStartLayer = nullptr;
	
	for (auto hiddenLayer : mHiddenLayerList)
	{
		delete hiddenLayer;
		hiddenLayer = nullptr;
	}

	delete mFinalLayer;
	mFinalLayer = nullptr;
}

