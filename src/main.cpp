#include <iostream>

#include <NeuralNetwork.h>

int main()
{
    std::cout << "This is my first neural network library!" << std::endl;

    NeuralNetwork* neuralNetwork; 

    neuralNetwork = new NeuralNetwork();

    neuralNetwork->ComputeResult();

    delete neuralNetwork;

    std::cin.ignore();

}