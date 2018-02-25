#Author : Mathias Varinot
#Date : 25 February 2018

# compilation flag to report all warnings and enable debugging in the
# generated object files and executables
set (C_MAKE_C_FLAGS "-Wall -g")

# Search all files with specified extension in the current directory and assign to specified variable
file(GLOB SOURCE_FILES *.cpp *.h)

# Define target application eecutable and the list of source and header files
add_executable(NeuralNetwork ${SOURCE_FILES})