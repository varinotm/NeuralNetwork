#include <iostream>

#include "NeuralNetwork.h"
#include "Trainer.h"

#include <fstream>

int ReverseInt(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
void Read_Mnist(std::string filename, std::vector<std::vector<double> > &vec)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        file.read((char*)&n_rows, sizeof(n_rows));
        n_rows = ReverseInt(n_rows);
        file.read((char*)&n_cols, sizeof(n_cols));
        n_cols = ReverseInt(n_cols);
        for (int i = 0; i < number_of_images; ++i)
        {
            std::vector<double> tp;
            for (int r = 0; r < n_rows; ++r)
            {
                for (int c = 0; c < n_cols; ++c)
                {
                    unsigned char temp = 0;
                    file.read((char*)&temp, sizeof(temp));
                    tp.push_back((double)temp);
                }
            }
            vec.push_back(tp);
        }
    }
}

void Read_Mnist_Label(std::string filename, std::vector<double> &vec)
{
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        for (int i = 0; i < number_of_images; ++i)
        {
            unsigned char temp = 0;
            file.read((char*)&temp, sizeof(temp));
            vec.push_back((double)temp);
        }
    }
}



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

    // Read mnist dataset
    std::vector<std::vector<double>> trainingData;
    std::vector<double> trainingResult;
    Read_Mnist("train-images.idx3-ubyte", trainingData);
    Read_Mnist_Label("train-labels.idx1-ubyte", trainingResult);

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