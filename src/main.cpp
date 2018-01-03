#include <iostream>

#include "NeuralNetwork.h"
#include "Trainer.h"

//returns the exit code of the program
int main()
{
    std::cout << "This is my first neural network library!" << std::endl;

    NeuralNetwork* neuralNetwork; 
    Trainer* trainer;

    std::vector<int> nbNeuronPerLayer = { 2, 2, 2 };

    neuralNetwork = new NeuralNetwork(nbNeuronPerLayer);

    // Initialize the neural network, before training it
    neuralNetwork->InitializeBiasAndWeights();

    /// \todo Set the training data
    trainer = new Trainer();
    //trainer->SetTrainingData();

    /// \todo train the neural network
    trainer->SetNeuralNetwork(neuralNetwork);
    trainer->SetBatchSize(100);
    trainer->SetNumberOfIterations(1000);
    //trainer->Train();

    // Save the neural network in a file after training
    neuralNetwork->Save("myFirstNeuralNetwork.txt");

    // Load the saved neural network
    neuralNetwork->Load("myFirstNeuralNetwork.txt");

    /// \todo Set the neural network initial layer for testing purpose after training
    //neuralNetwork->SetInputLayer();

    // Compute the output result of the current neural network given an initial starting layer
    neuralNetwork->ComputeResult();

    delete neuralNetwork;

    std::cin.ignore();

}
