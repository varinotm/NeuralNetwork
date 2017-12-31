#include <iostream>

#include "NeuralNetwork.h"
#include "Trainer.h"

//returns the exit code of the program
int main()
{
    std::cout << "This is my first neural network library!" << std::endl;

    NeuralNetwork* neuralNetwork; 
    Trainer* trainer;

    std::vector<int> nbNeuronPerLayer = { 784, 800, 10 };

    neuralNetwork = new NeuralNetwork(nbNeuronPerLayer);

    // Initialize the neural network, before training it
    neuralNetwork->Initialize();

    /// Set the training data
    trainer = new Trainer();
    //trainer->SetTrainingData();

    /// train the neural network
    trainer->SetNeuralNetwork(neuralNetwork);
    trainer->SetBatchSize(100);
    trainer->SetNumberOfIterations(1000);
    //trainer->Train();

    // Compute the output result of the current neural network given an initial starting layer
    neuralNetwork->ComputeResult();

    delete neuralNetwork;

    std::cin.ignore();

}
