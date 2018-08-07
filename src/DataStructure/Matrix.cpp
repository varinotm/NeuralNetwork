#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(unsigned int nbRows, unsigned int nbCols)
{
   mMatrix.resize(nbRows);
   for (unsigned int i = 0; i < mMatrix.size(); i++)
   {
      mMatrix[i].resize(nbCols);
   }
   mNbRows = nbRows;
   mNbCols = nbCols;
}
                                                                                                                                                          
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs)
{
   mMatrix = rhs.mat;
   mNbRows = rhs.get_rows();
   mNbCols = rhs.get_cols();
}

// Assignment Operator                                                                                                                                                        
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
   if (&rhs == this)
      return *this;

   unsigned nbRows = rhs.GetNbRows();
   unsigned nbCols = rhs.GetNbCols();

   mat.resize(nbRows);
   for (unsigned i = 0; i<mat.size(); i++)
   {
      mat[i].resize(nbCols, 0.0);
   }

   for (unsigned i = 0; i<nbRows; i++)
   {
      for (unsigned j = 0; j<nbCols; j++)
      {
         mat[i][j] = rhs(i, j);
      }
   }
   mNbRows = nbRows;
   mNbCols = nbCols;

   return *this;
}

// Addition of two matrices                                                                                                                                                   
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
   Matrix result(mNbRows, mNbCols, 0.0);

   for (unsigned i = 0; i<mNbRows; i++)
   {
      for (unsigned j = 0; j<mNbCols; j++)
      {
         result(i, j) = mMatrix[i][j] + rhs(i, j);
      }
   }

   return result;
}

// Cumulative addition of this matrix and another                                                                                                                             
template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
   unsigned nbRows = rhs.GetNbRows();
   unsigned nbCols = rhs.GetNbCols();

   for (unsigned i = 0; i<nbRows; i++)
   {
      for (unsigned j = 0; j<nbCols; j++)
      {
         mMatrix[i][j] += rhs(i, j);
      }
   }
   return *this;
}

// Substraction of two matrices                                                                                                                                                   
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs)
{
   Matrix result(mNbRows, mNbCols, 0.0);

   for (unsigned i = 0; i<mNbRows; i++)
   {
      for (unsigned j = 0; j<mNbCols; j++)
      {
         result(i, j) = mMatrix[i][j] - rhs(i, j);
      }
   }

   return result;
}

// Cumulative substraction of this matrix and another                                                                                                                             
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
   unsigned nbRows = rhs.GetNbRows();
   unsigned nbCols = rhs.GetNbCols();

   for (unsigned i = 0; i<nbRows; i++)
   {
      for (unsigned j = 0; j<nbCols; j++)
      {
         mMatrix[i][j] -= rhs(i, j);
      }
   }
   return *this;
}
// Left multiplication of this matrix and another                                                                                                                              
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
   unsigned rows = rhs.get_rows();
   unsigned cols = rhs.get_cols();
   QSMatrix result(rows, cols, 0.0);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         for (unsigned k = 0; k<rows; k++)
         {
            result(i, j) += mMatrix[i][k] * rhs(k, j);
         }
      }
   }

   return result;
}

// Cumulative left multiplication of this matrix and another                                                                                                                  
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& rhs)
{
   Matrix result = (*this) * rhs;
   (*this) = result;
   return *this;
}

// Matrix/scalar addition                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs)
{
   Matrix result(mNbRows, mNbCols);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result(i, j) = mMatrix[i][j] + rhs;
      }
   }

   return result;
}

// Matrix/scalar substraction                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs)
{
   Matrix result(mNbRows, mNbCols);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result(i, j) = mMatrix[i][j] - rhs;
      }
   }

   return result;
}

// Matrix/scalar multiplication                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs)
{
   Matrix result(mNbRows, mNbCols);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result(i, j) = mMatrix[i][j] * rhs;
      }
   }

   return result;
}

// Matrix/scalar division                                                                                                                                                     
template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs)
{
   Matrix result(mNbRows, mNbCols);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result(i, j) = mMatrix[i][j] / rhs;
      }
   }

   return result;
}

// Multiply a matrix with a vector                                                                                                                                            
template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs)
{
   std::vector<T> result(rhs.size());

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result[i] = mMatrix[i][j] * rhs[j];
      }
   }

   return result;
}

// Obtain a vector of the diagonal elements                                                                                                                                   
template<typename T>
std::vector<T> Matrix<T>::GetDiagonalVector()
{
   std::vector<T> result(mNbRows, 0.0);

   for (unsigned i = 0; i<mNbRows; i++)
   {
      result[i] = mMatrix[i][i];
   }

   return result;
}

// Access the individual elements                                                                                                                                             
template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col)
{
   return mMatrix[row][col];
}

// Access the individual elements (const)                                                                                                                                     
template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
   return mMatrix[row][col];
}

// Get the number of rows of the matrix                                                                                                                                       
template<typename T>
unsigned Matrix<T>::GetNbRows() const
{
   return mNbRows;
}

// Get the number of columns of the matrix                                                                                                                                    
template<typename T>
unsigned Matrix<T>::GetNbCols() const
{
   return mNbCols;
}

// Calculate a transpose of this matrix                                                                                                                                       
template<typename T>
Matrix<T> Matrix<T>::Transpose()
{
   QSMatrix result(rows, cols, 0.0);

   for (unsigned i = 0; i<rows; i++)
   {
      for (unsigned j = 0; j<cols; j++)
      {
         result(i, j) = mMatrix[j][i];
      }
   }

   return result;
}