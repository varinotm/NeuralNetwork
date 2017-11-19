#pragma once

class Layer;

/// Class that connects 2 layers
class LayerConnection
{
public:
	/// Constructor
	LayerConnection(Layer* layerInput, Layer* layerOutput);

	/// Destructor
	~LayerConnection();

private:
	/// Value going from 0 to 1
	double value;

};