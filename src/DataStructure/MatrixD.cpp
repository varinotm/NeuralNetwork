#include "MatrixD.h"
#include <omp.h>
#include <iostream>

MatrixD::MatrixD(const int& nbRows, const int& nbCols)
{
    mMatrix = new double[nbRows *nbCols];
    mNbRows = nbRows;
    mNbCols = nbCols;
}

MatrixD::~MatrixD()
{
    delete[] mMatrix;
}

void MatrixD::Multiply(const MatrixD& lhs, const MatrixD& rhs)
{

    for (int i = 0; i < mNbRows; i++)
    {
        for (int j = 0; j < mNbCols; j++)
        {
            mMatrix[i*mNbRows + j] = 0.0;
        }
    }
#pragma omp parallel for
    for (int i = 0; i < lhs.mNbRows; i++)
    {
        for (int j = 0; j < rhs.mNbCols; j++)
        {
            for (int k = 0; k < lhs.mNbCols; k++)
            {
                mMatrix[i*mNbRows + j] += lhs.mMatrix[i*lhs.mNbRows + k] * rhs.mMatrix[k *lhs.mNbRows + j];
            }
        }
    }
}

// Access the individual elements                                                                                                                                             
double& MatrixD::operator()(const int& row, const int& col)
{
    return mMatrix[row * mNbRows + col];
}

const double& MatrixD::operator()(const int& row, const int& col) const
{
    return mMatrix[row * mNbRows + col];
}

int MatrixD::GetNbRows() const
{
    return mNbRows;
}

int MatrixD::GetNbCols() const
{
    return mNbCols;
}