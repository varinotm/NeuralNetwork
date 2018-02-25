#include <iostream>

#include "NeuralNetwork.h"
#include "Trainer.h"

#include "MnistReader.h"
    
#include <ctime>


//returns the exit code of the program
int main()
{

    time_t now;
    time(&now);
    srand((unsigned int)now);

    std::cout << "This is my first neural network library!" << std::endl;

    NeuralNetwork* neuralNetwork; 
    Trainer* trainer;

    std::vector<int> nbNeuronPerLayer = { 784, 800, 10};

    neuralNetwork = new NeuralNetwork(nbNeuronPerLayer);

    // Initialize the neural network, before training it
    neuralNetwork->InitializeBiasAndWeights();

    // Read mnist dataset
    std::vector<std::pair<double*, double*>> trainingData;
    /*double* array1 = new double[2];
    double* array2 = new double[2];
    double* array3 = new double[2];
    double* array4 = new double[2];

    array1[0] = 0;
    array1[1] = 0;

    array2[0] = 0;
    array2[1] = 1;

    array3[0] = 1;
    array3[1] = 0;

    array4[0] = 1;
    array4[1] = 1;

    trainingData.push_back(std::make_pair(array1, array3));
    trainingData.push_back(std::make_pair(array2, array2));
    trainingData.push_back(std::make_pair(array3, array2));
    trainingData.push_back(std::make_pair(array4, array2));*/
    MnistReader::ReadMnistInputOutput("train-images.idx3-ubyte", 
                                      "train-labels.idx1-ubyte", 
                                      trainingData);

    // Set the training data and train the neural network
    trainer = new Trainer();
    trainer->SetTrainingData(trainingData);
    trainer->SetNeuralNetwork(neuralNetwork);
    trainer->SetBatchSize(1);
    trainer->SetNumberOfIterations(100000);
    trainer->Train(0.1);

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