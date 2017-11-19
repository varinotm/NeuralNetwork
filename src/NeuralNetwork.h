#pragma once

#include <LayerFactory.h>

#include <vector>

class NeuralNetwork
{
public:
	NeuralNetwork();

	~NeuralNetwork();

private:
	LayerFactory mLayerFactory;

	StartLayer* mStartLayer;
	std::vector<HiddenLayer*> mHiddenLayerList;
	FinalLayer* mFinalLayer;
};