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

Matrix::Matrix(vector<double> vec, int row, int column)
    : _vec(vec), _row(row), _column(column)

{
}

//-----------------------------
// Arithmetic Operators
//-----------------------------

// make the change on other matrix
Matrix Matrix::operator-()
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) = -i;
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

Matrix Matrix::operator*=(double d)
{
    Matrix temp{this->_vec, this->_row, this->_column};
    for (unsigned i = 0; i < temp._vec.size(); i++)
    {
        temp._vec.at(i) *= d;
    }

    return temp;
}
//-----------------------------
// Comparison Operators
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
        cout << "sum1 " << sum1 <<"sum2  " << sum2 <<endl;                ///**********

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

    cout << "sum1 " << sum1 <<"sum2  " << sum2 <<endl;              //////////******
    return (sum1 < sum2 ? true : false);
}
bool Matrix::operator>(const Matrix &other) const
{
    int sum1 = std::accumulate(this->_vec.begin(), this->_vec.end(), 0);
    int sum2 = std::accumulate(other._vec.begin(), other._vec.end(), 0);
    return (sum1 > sum2 ? true : false);
}

//-----------------------------
// Friend Operators
//-----------------------------
zich::Matrix zich::operator*(double d, zich::Matrix &mat)
{
//  Matrix temp{mat., mat._row , mat._column};
    return mat;
}

Matrix Matrix::operator*(Matrix &other)
{
    if(this->_column != other._row){
        throw "wrong mult";
    }
    unsigned long size = (unsigned long)(this->_row*other._column);
   vector<double> tVec(size, 0);

    Matrix temp{tVec, this->_column, other._row};
    
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int count = 0;
// while (k < temp._vec.size())
// {
//     while(j < other._column){
//        count += this->_vec.at(i)*other._vec.at(j); 
//         i++;
//         j+=other._column;
//     }
//     temp._vec.at(k++) = count;
//     count = 0;
// }



    return temp;
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


