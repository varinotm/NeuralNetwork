#pragma once

#include <string>
#include <vector>

namespace MnistReader
{
    /// Function
    int ReverseInt(int i);

    void ReadMnistInputOutput(std::string inputFilename,
                              std::string outputFilename,
                              std::vector<std::pair<double*, double*>> &trainingData);
}