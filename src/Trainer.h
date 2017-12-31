#pragma once

#include <vector>
#include <utility>

class NeuralNetwork;

/// class that will make a neural network learn from a given set
class Trainer
{
public:
    /// Constructor
    Trainer();

    /// Destructor
    ~Trainer() = default;

    /// Set the neural network that needs to learn
    void SetNeuralNetwork(NeuralNetwork* neuralNetwork);

    /// Set the data from which the neural network will learn
    /// \warn the training data should match the start layer(input) and end layer(output)
    /// of the neural network.
    void SetTrainingData(std::vector<std::pair<double*, double*>> trainingData);

    /// Set the batch size of each iteration of the training. This number must
    /// be below the total number of the training data
    void SetBatchSize(int nbBatchSize);

    /// Set the number of iterations to train
    /// each iteration will take randomly a number from the training dataset equal
    /// to the batch size
    void SetNumberOfIterations(int nbIterations);

    /// Start training
    /// Call when the trainer parameters has been set
    void Train();

private:
    /// The current neural network to train
    NeuralNetwork* mNeuralNetwork;

    /// The current training data
    std::vector<std::pair<double*, double*>> mTrainingData;

    /// the desired batch size to train [default = 1]
    int mNbBatchSize;

    /// The desired number of iterations to train [default = 10]
    int mNbIterations;
};