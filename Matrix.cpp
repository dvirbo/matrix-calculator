// @AUTHOR: dvir borochov

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <tgmath.h>
#include "Matrix.hpp"

using namespace std;
using namespace zich;

// initializer lists of vec, row and column
Matrix::Matrix(vector<double> vec, int row, int column)
    : _vec(vec), _row(row), _column(column)

{
}

//-----------------------------
// Arithmetic Operators:
//-----------------------------

// make the change on other matrix
Matrix Matrix::operator-()
{
    Matrix temp{this->_vec, this->_row, this->_column};
    int t = 0;
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        t = temp._vec.at(i);
        t = -t;
        temp._vec.at(i) = t;
    }
    return temp;
}

Matrix Matrix::operator-(const Matrix &other)
{
    if (this->_row != other._row || this->_column != other._column)
    {
        throw "can't make Arithmetic Operators between Different matrices";
    }
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) = this->_vec.at(i) - other._vec.at(i);
    }

    return temp;
}
// here we change the orginal mat
Matrix Matrix::operator-=(const Matrix &other)
{
    if (this->_row != other._row || this->_column != other._column)
    {
        throw "can't make Arithmetic Operators between Different matrices";
    }
    for (unsigned i = 0; i < this->_vec.size(); i++)
    {
        this->_vec.at(i) = this->_vec.at(i) - other._vec.at(i);
    }

    return *this;
}

Matrix Matrix::operator+() const
{
    // for (unsigned i = 0; i < this->_vec.size(); i++)  ???????
    // {
    //     this->_vec.at(i) * (-1);
    // }
    return *this;
}
Matrix Matrix::operator+(const Matrix &other)
{
    if (this->_row != other._row || this->_column != other._column)
    {
        throw "can't make Arithmetic Operators between Different matrices";
    }
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) = this->_vec.at(i) + other._vec.at(i);
    }

    return temp;
}
Matrix Matrix::operator+=(const Matrix &other)
{
    if (this->_row != other._row || this->_column != other._column)
    {
        throw "can't make Arithmetic Operators between Different matrices";
    }
    for (unsigned i = 0; i < this->_vec.size(); i++)
    {
        this->_vec.at(i) = this->_vec.at(i) + other._vec.at(i);
    }

    return *this;
}

Matrix Matrix::operator--(int num)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) -= 1;
    }

    return temp;
}

Matrix Matrix::operator++(int num)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) += 1;
    }

    return temp;
}

//-----------------------------
// Comparison Operators:
//-----------------------------

bool Matrix::operator!=(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);

    return (sum1 != sum2 ? true : false);
}

bool Matrix::operator==(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);
    return (sum1 == sum2 ? true : false);
}

bool Matrix::operator<=(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);

    return (sum1 <= sum2 ? true : false);
}
bool Matrix::operator>=(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);

    return (sum1 >= sum2 ? true : false);
}

bool Matrix::operator<(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);

    return (sum1 < sum2 ? true : false);
}
bool Matrix::operator>(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);
    return (sum1 > sum2 ? true : false);
}

//-----------------------------
// mult Operators:
//-----------------------------

// mult mat with some num.. not change the orginal mat
zich::Matrix zich::operator*(double d, zich::Matrix &mat)
{
    Matrix temp{mat._vec, mat._row, mat._column};
    unsigned t = 0;
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        t = temp._vec.at(i);
        t *= d;
        temp._vec.at(i) = t;
    }
    return temp;
}

// mult 2 mat..return the new mat the mult of them
Matrix Matrix::operator*(Matrix &other)
{
    if (this->_column != other._row)
    {
        throw "wrong mult";
    }
    unsigned long size = (unsigned long)(this->_row * other._column);
    vector<double> tVec(size, 0);

    Matrix temp{tVec, this->_column, other._row};

    for (unsigned int i = 0; i < this->_row; ++i)
        for (unsigned int j = 0; j < other._column; ++j)
            for (unsigned int k = 0; k < this->_column; ++k)
            {
                temp._vec.at(i + j) += this->_vec.at(i + k) * other._vec.at(k + j);
            }

    return temp;
}

// mult mat with some num, change and return the orginal mat
Matrix Matrix::operator*=(double d)
{
    int t = 0;
    for (unsigned int i = 0; i < this->_vec.size(); i++)
    {
        t = this->_vec.at(i);
        t *= d;
        this->_vec.at(i) = t;
    }
    return *this;
}

//-----------------------------
// I/O Operators
//-----------------------------
ostream &zich::operator<<(std::ostream &out, Matrix mat)
{
    // for iner using:
    unsigned int ii = 0;
    unsigned int jj = 0;

    for (unsigned int i = 0; i < mat._row; ++i)
    {
        for (unsigned int j = 0; j < mat._column; ++j)
        {
            cout << " " << mat._vec.at(ii + jj);
            jj++;
            if (j == mat._column - 1)
                cout << endl;
            jj = 0;
            ii++;
        }
    }

    return out;
}
istream &zich::operator>>(std::istream &in, Matrix &mat)
{

    std::vector<double> arr;
    int r,c;

   // in >> arr >> r >>c;

    return in;
}
