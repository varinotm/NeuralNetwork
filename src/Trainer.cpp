#include "Trainer.h"

#include "NeuralNetwork.h"

#include <algorithm>

namespace
{
    template<class BidiIter >
    BidiIter random_unique(BidiIter begin, BidiIter end, size_t num_random)
    {
        size_t left = std::distance(begin, end);
        while (num_random--)
        {
            BidiIter r = begin;
            std::advance(r, rand() % left);
            std::swap(*begin, *r);
            ++begin;
            --left;
        }
        return begin;
    }
}

Trainer::Trainer()
{
    mNeuralNetwork = nullptr;
    mNbBatchSize = 1;
    mNbIterations = 10;
}

void Trainer::SetNeuralNetwork(NeuralNetwork* neuralNetwork)
{
    mNeuralNetwork = neuralNetwork;
}

void Trainer::SetTrainingData(std::vector<std::pair<double*, double*>> trainingData)
{
    mTrainingData = trainingData;
}

void Trainer::SetBatchSize(int nbBatchSize)
{
    mNbBatchSize = nbBatchSize;
}

void Trainer::SetNumberOfIterations(int nbIterations)
{
    mNbIterations = nbIterations;
}

void Trainer::Train(double learningRate)
{
    for (int i = 0; i < mNbIterations; i++)
    {
        if (i == 9)
        {
            int allo = 3;
        }
        // Take random training sets for the current iteration
        random_unique(mTrainingData.begin(), mTrainingData.end(), mNbBatchSize);

        // We iterate through these chosen data and learn from this set
        for (int j = 0; j < mNbBatchSize; j++)
        {
            mNeuralNetwork->SetInputLayer(mTrainingData[j].first);
            mNeuralNetwork->ComputeResult();

            mNeuralNetwork->ComputeDelta(mTrainingData[j].second);

            /// \todo Change weight and bias only when the batch is complete
            mNeuralNetwork->UpdateWeightAndBias(learningRate);
        }
    }
}