#pragma once

#include <vector>

class MatrixD
{
public:
    /// Constructor of the matrix class
    /// \param[in] nbRows the number of rows in the created matrix
    /// \param[in] nbCols the number of columns in the created matrix
    MatrixD(const int& nbRows, const int& nbCols);

    /// this will not deallocate the content of the matrix, it has to be deallocaed explicitely
    ~MatrixD(); 

    /// Multiply two matrix and the result will be stored in the matrix.
    /// no new pointers will be created, the pointed values will change accordingly
    void Multiply(const MatrixD& lhs, const MatrixD& rhs);

    // Access the individual elements                                                                                                                                                                                               
    double& operator()(const int& row, const int& col);
    const double& operator()(const int& row, const int& col) const;

    int GetNbRows() const;
    int GetNbCols() const;

private:
    /// The matrix
    double* mMatrix;

    /// The number of rows in the matrix
    int mNbRows;

    /// The number of columns in the matrix
    int mNbCols;
};