#include "MnistReader.h"

#include <utility>
#include <fstream>

namespace MnistReader
{
    int ReverseInt(int i)
    {
        unsigned char ch1, ch2, ch3, ch4;
        ch1 = i & 255;
        ch2 = (i >> 8) & 255;
        ch3 = (i >> 16) & 255;
        ch4 = (i >> 24) & 255;
        return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
    }

    void ReadMnistInputOutput(std::string inputFilename,
                              std::string outputFilename,
                              std::vector<std::pair<double*, double*>> &trainingData)
    {
        std::ifstream imageFile(inputFilename, std::ios::binary);
        std::ifstream labelFile(outputFilename, std::ios::binary);

        if (imageFile.is_open() && labelFile.is_open())
        {
            int magic_number = 0;
            int number_of_images = 0;
            int nbRows = 0;
            int nbCols = 0;


            labelFile.read((char*)&magic_number, sizeof(magic_number));
            magic_number = ReverseInt(magic_number);
            labelFile.read((char*)&number_of_images, sizeof(number_of_images));
            number_of_images = ReverseInt(number_of_images);

            // We assume that the image file will have the same number of data as the label file
            imageFile.read((char*)&magic_number, sizeof(magic_number));
            magic_number = ReverseInt(magic_number);
            imageFile.read((char*)&number_of_images, sizeof(number_of_images));
            number_of_images = ReverseInt(number_of_images);
            imageFile.read((char*)&nbRows, sizeof(nbRows));
            nbRows = ReverseInt(nbRows);
            imageFile.read((char*)&nbCols, sizeof(nbCols));
            nbCols = ReverseInt(nbCols);

            for (int i = 0; i < number_of_images; ++i)
            {
                double* inputData = new double[nbRows*nbCols];
                double* outputData = new double[10];

                // We create the input data of the image
                for (int r = 0; r < nbRows; ++r)
                {
                    for (int c = 0; c < nbCols; ++c)
                    {
                        unsigned char temp = 0;
                        imageFile.read((char*)&temp, sizeof(temp));
                        inputData[r*nbCols + c] = (double)temp / 255.0;
                    }
                }

                for (int i = 0; i < 10; i++)
                {
                    outputData[i] = 0.0;
                }

                unsigned char temp = 0;
                labelFile.read((char*)&temp, sizeof(temp));
                outputData[(int)temp] = 1.0;

                // We then create the output data of the label
                trainingData.push_back(std::make_pair(inputData, outputData));
            }
        }
    }

}