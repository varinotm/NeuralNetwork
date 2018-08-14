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

void MatrixD::Reset()
{
    for (int i = 0; i < mNbRows; i++)
    {
        for (int j = 0; j < mNbCols; j++)
        {
            mMatrix[i*mNbCols + j] = 0.0;
        }
    }
}

void MatrixD::Add(MatrixD* matrix)
{
    for (int i = 0; i < mNbRows; i++)
    {
        for (int j = 0; j < mNbCols; j++)
        {
            mMatrix[i*mNbCols + j] += matrix->mMatrix[i*mNbCols + j];
        }
    }
}

void MatrixD::Multiply(MatrixD* lhs, MatrixD* rhs)
{
    // reset all values to 0.0
    Reset();
    // Use parallelism for matrix multiplication
#pragma omp parallel for
    for (int i = 0; i < lhs->mNbRows; i++)
    {
        for (int j = 0; j < rhs->mNbCols; j++)
        {
            for (int k = 0; k < lhs->mNbCols; k++)
            {
                mMatrix[i*mNbCols + j] += lhs->mMatrix[i*lhs->mNbCols + k] * rhs->mMatrix[k *rhs->mNbCols + j];
            }
        }
    }
}

// Access the individual elements                                                                                                                                             
double& MatrixD::operator()(const int& row, const int& col)
{
    return mMatrix[row * mNbCols + col];
}

const double& MatrixD::operator()(const int& row, const int& col) const
{
    return mMatrix[row * mNbCols + col];
}

int MatrixD::GetNbRows() const
{
    return mNbRows;
}

int MatrixD::GetNbCols() const
{
    return mNbCols;
}

double*& MatrixD::GetMatrix()
{
    return mMatrix;
}