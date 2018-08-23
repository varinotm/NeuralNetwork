#Author : Mathias Varinot
#Date : 25 February 2018

# Activate C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME "NeuralNetworkProject")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")

# Defining the project name
project(${PROJECT_NAME})

# Add subdirectory to the project : The CMakeLists.txt file in that subdirectory
# will be used to set up the project
 
add_subdirectory(exe)
add_subdirectory(src)