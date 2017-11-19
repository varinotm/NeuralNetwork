#pragma once

#include <ILayer.h>

class FinalLayer;

/// Layer class containing a list of neurons
class HiddenLayer : public ILayer
{
public:
	/// Constructor
	HiddenLayer();

	/// Destructor
	~HiddenLayer() = default;

	/// Set the output Layer. Will overwrite any previous output layer
	//@{
	void SetOutputLayer(HiddenLayer* hiddenLayer);
	void SetOutputLayer(FinalLayer* finalLayer);
	//@}

private:
	ILayer* mLayer;
};