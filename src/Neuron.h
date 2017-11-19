#pragma once


/// Neuron in a layer. Its value goes from 0 to 1
class Neuron
{
public:
	/// Constructor
	Neuron();

	/// Destructor
	~Neuron();

private:
	/// Value going from 0 to 1
	double mValue;


};