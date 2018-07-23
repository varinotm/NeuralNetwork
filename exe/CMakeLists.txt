# Define target application executable and the list of source and header files
add_executable(NeuralNetwork main.cpp)

# copy files from resources to build
FILE(
   COPY
      ${CMAKE_CURRENT_SOURCE_DIR}/resources/
   DESTINATION
      ${CMAKE_CURRENT_BINARY_DIR}/resources/
)

target_link_libraries(NeuralNetwork ${PROJECT_NAME}_staticLib)