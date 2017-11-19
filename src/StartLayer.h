#pragma once

#include <ILayer.h>

class HiddenLayer;
class FinalLayer;

/// Layer class containing a list of neurons
class StartLayer : public ILayer
{
public:
	/// Constructor
	StartLayer();

	/// Destructor
	~StartLayer() = default;

	/// Set the output Layer. Will overwrite any previous output layer
	//@{
	void SetOutputLayer(HiddenLayer* hiddenLayer);
	void SetOutputLayer(FinalLayer* finalLayer);
	//@}

private:
	ILayer* mLayer;
};