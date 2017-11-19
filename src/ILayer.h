#pragma once

#include <vector>

class Neuron;

/// Layer class containing a list of neurons
class ILayer
{
public:
	/// Constructor
	ILayer();

	/// Destructor
	~ILayer();

private:
	std::vector<Neuron*> mNeuronList;
};