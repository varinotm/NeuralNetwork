#include <NeuralNetwork.h>

#include <StartLayer.h>
#include <HiddenLayer.h>
#include <FinalLayer.h>

#include <LayerConnection.h>

NeuralNetwork::NeuralNetwork()
{
	// Test : 1 start layer, 2 hidden layers, 1 output layer

	// Initialize layers
	mStartLayer = mLayerFactory.CreateStartLayer();

	mHiddenLayerList.push_back(mLayerFactory.CreateHiddenLayer());
	mHiddenLayerList.push_back(mLayerFactory.CreateHiddenLayer());

	mFinalLayer = mLayerFactory.CreateFinalLayer();

	// Create connections
	mLayerConnectionList.push_back(new LayerConnection(mStartLayer, mHiddenLayerList[0]));
	mLayerConnectionList.push_back(new LayerConnection(mHiddenLayerList[0], mHiddenLayerList[1]));
	mLayerConnectionList.push_back(new LayerConnection(mHiddenLayerList[1], mFinalLayer));
}

NeuralNetwork::~NeuralNetwork()
{
	for (auto layerConnection : mLayerConnectionList)
	{
		delete layerConnection;
		layerConnection = nullptr;
	}
	mLayerConnectionList.clear();

	delete mStartLayer;
	mStartLayer = nullptr;
	
	for (auto hiddenLayer : mHiddenLayerList)
	{
		delete hiddenLayer;
		hiddenLayer = nullptr;
	}
	mHiddenLayerList.clear();

	delete mFinalLayer;
	mFinalLayer = nullptr;
}

