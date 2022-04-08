// @AUTHOR: dvir borochov

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <tgmath.h>
#include <algorithm>
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
    return (*this = *this + other);
}
Matrix Matrix::operator-=(const Matrix &other)
{
    if (this->_row != other._row || this->_column != other._column)
    {
        throw "can't make Arithmetic Operators between Different matrices";
    }
    return (*this = *this - other);
}

// ---------------------------------------------------------------
// inc and dec operators
// ---------------------------------------------------------------
Matrix Matrix::operator++() // pre (++x)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) -= 1;
    }

    return temp;
}

Matrix Matrix::operator--() // pre (--x)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) -= 1;
    }

    return temp;
}

Matrix Matrix::operator--(int num) // post (x--)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) -= 1;
    }

    return temp;
}

Matrix Matrix::operator++(int num) // post (x++)
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
    // int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    // int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);

    // return (sum1 != sum2 ? true : false);
    return !(*this == other);
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
zich::Matrix zich::operator*(double d, Matrix &mat)
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

Matrix Matrix::operator*(double d)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    unsigned t = 0;
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        t = temp._vec.at(i);
        t *= d;
        temp._vec.at(i) = t;
    }
    return temp;
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
    string s;
    string token;
    string delimiter = ", ";
    string ans;
    size_t rowLen = 0; // the length of the row
    size_t pos = 0;
    double data = 0;
    std::vector<double> finvec;

    getline(in, s); // scan the str from the user:

    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        if (rowLen == 0)
        {
            rowLen = token.length();
        }
        else
        {
            if (token.length() != rowLen)
            {
                throw invalid_argument("the rows must be the same length\n");
            }
        }
        ans += token;
        std::cout << token << endl;
        s.erase(0, pos + delimiter.length());
    }
    if (s.length() != rowLen) // check if the final part is valid
    {
        throw invalid_argument("the rows must be the same length\n");
    }
    ans += s;
    ans.erase(std::remove(ans.begin(), ans.end(), '['), ans.end()); // erase '[' from the str
    std::replace(ans.begin(), ans.end(), ']', ' '); // replace all ']' to ' '
    std::stringstream iss(ans); //parse str to vector of double:

    while (iss >> data)
    {
        finvec.push_back(data);
    }
    // allocate the final data to the matrix:
    mat._row = rowLen;
    mat._column = finvec.size() / rowLen;
    mat._vec = finvec;
    return in;
}
