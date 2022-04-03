// @AUTHOR: dvir borochov

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

Matrix::Matrix(vector<double> vec, int row, int column)
    : _vec(vec), _row(row), _column(column)

{
}

//-----------------------------
// Arithmetic Operators
//-----------------------------

Matrix Matrix::operator-()
{
    return *this;
}

Matrix Matrix::operator-(const Matrix &mat)
{
    return *this;
}
Matrix Matrix::operator-=(const Matrix &mat)
{
    return *this;
}

Matrix Matrix::operator+() const
{
    return *this;
}
Matrix Matrix::operator+(const Matrix &mat)
{
    return *this;
}
Matrix Matrix::operator+=(const Matrix &mat)
{
    return *this;
}

Matrix Matrix::operator--(int num)
{
    return *this;
}

Matrix Matrix::operator++(int num)
{
    return *this;
}

Matrix Matrix::operator*=(double d)
{
    return *this;
}
//-----------------------------
// Comparison Operators
//-----------------------------

bool Matrix::operator!=(const Matrix &other) const
{
    return false;
}

bool Matrix::operator==(const Matrix &other) const
{
    return false;
}

bool Matrix::operator<=(const Matrix &other) const
{
    return false;
}
bool Matrix::operator>=(const Matrix &other) const
{
    return false;
}

bool Matrix::operator<(const Matrix &other) const
{
    return false;
}
bool Matrix::operator>(const Matrix &other) const
{
    return false;
}

//-----------------------------
// Friend Operators
//-----------------------------
Matrix operator*(double d, Matrix &mat)
{
    return mat;
}

Matrix Matrix::operator*(Matrix &mat)
{
    return mat;
}

//-----------------------------
// I/O Operators
//-----------------------------
ostream &zich::operator<<(std::ostream &out, Matrix mat)
{
    return out;
}
istream &zich::operator>>(std::istream &in, Matrix &mat)
{
    return in;
}