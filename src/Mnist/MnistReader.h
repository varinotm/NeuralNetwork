#pragma once

#include <string>
#include <vector>

namespace MnistReader
{
    /// Function
    int ReverseInt(int i);

    /// Read the mnist dataset and put the values into the data
    /// \param[in] inputFilename the image file values each pixel of the image has a value between 0 and 255
    /// \param[in] outputFilename the result of each image. value between 0 and 9
    /// \param[in/out] trainingData the data created after reading from mnist dataset
    /// \return true if the reading of mnist dataset was successful, else false
    bool ReadMnistInputOutput(std::string inputFilename,
                              std::string outputFilename,
                              std::vector<std::pair<double*, double*>> &trainingData);
}