#pragma once

#include <vector>


/// Matrix class taken from Quantstart website
template <class T>
class Matrix
{
public:
   /// Constructor of the matrix class
   /// \param[in] nbRows the number of rows in the created matrix
   /// \param[in] nbCols the number of columns in the created matrix
   Matrix<T>(unsigned int nbRows, unsigned int nbCols);

   /// Destructor
   ~Matrix() = default;

   /// Copy constructor
   /// \param[in] matrix the matrix to copy
   Matrix<T>(const Matrix<T>& matrix);

   /// copy operator
   Matrix<T>& operator=(const Matrix& matrix);

   /// Matrix/Matrix operations
   Matrix<T> operator+(const Matrix<T>& rhs);
   Matrix<T>& operator+=(const Matrix<T>& rhs);
   Matrix<T> operator-(const Matrix<T>& rhs);
   Matrix<T>& operator-=(const Matrix<T>& rhs);
   Matrix<T> operator*(const Matrix<T>& rhs);
   Matrix<T>& operator*=(const Matrix<T>& rhs);
   Matrix<T> Transpose();

   /// Matrix/scalar operations
   Matrix<T> operator+(const T& rhs);
   Matrix<T> operator-(const T& rhs);
   Matrix<T> operator*(const T& rhs);
   Matrix<T> operator/(const T& rhs);

   // Matrix/vector operations                                                                                                                                                                                                     
   std::vector<T> operator*(const std::vector<T>& rhs);
   std::vector<T> GetDiagonalVector();

   // Access the individual elements                                                                                                                                                                                               
   T& operator()(const unsigned& row, const unsigned& col);
   const T& operator()(const unsigned& row, const unsigned& col) const;

   // Access the row and column sizes                                                                                                                                                                                              
   unsigned int GetNbRows() const;
   unsigned int GetNbCols() const;

private:
   /// The matrix
   std::vector<std::vector<T>> mMatrix;

   /// The number of rows in the matrix
   unsigned int mNbRows;

   /// The number of columns in the matrix
   unsigned int mNbCols;
};