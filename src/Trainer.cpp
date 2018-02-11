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

void Trainer::Train()
{
    for (int i = 0; i < mNbIterations; i++)
    {
        // Take random training sets for the current iteration
        random_unique(mTrainingData.begin(), mTrainingData.end(), mNbBatchSize);

        // The cost function of this iteration
        std::vector<double> batchCost;
        batchCost.resize(mNeuralNetwork->GetOutputSize());

        // We iterate through these chosen data and learn from this set
        for (int j = 0; j < mNbBatchSize; j++)
        {
            mNeuralNetwork->SetInputLayer(mTrainingData[j].first);
            mNeuralNetwork->ComputeResult();

            /// \todo Change weight, bias according to result!
            auto result = mNeuralNetwork->GetResult();

            for (unsigned int k = 0; k < result.size(); k++)
            {
                batchCost[k] += pow(result[k] - mTrainingData[j].second[k], 2);
            }
        }

        /// Calculate the mean of the batch cost
        for (unsigned int j = 0; j < batchCost.size(); j++)
        {
            batchCost[j] /= mNbBatchSize;
        }
    }
}