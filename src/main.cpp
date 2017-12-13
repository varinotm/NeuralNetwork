#include <iostream>

#include "NeuralNetwork.h"

//returns the exit code of the program
int main()
{
    std::cout << "This is my first neural network library!" << std::endl;

    NeuralNetwork* neuralNetwork; 

    neuralNetwork = new NeuralNetwork();

    neuralNetwork->ComputeResult();

    delete neuralNetwork;

    std::cin.ignore();

}
