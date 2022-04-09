#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"
#include "doctest.h"

using namespace zich;
using namespace std;

std::vector<double> vec1 = {1, 0, 0, 1};
vector<double> vec2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
vector<double> vec3 = {1, 2, 0, 1, 1, 1};
vector<double> vec4 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
Matrix a{vec1, 2, 2};
Matrix b{vec2, 3, 3};
Matrix c{vec3, 2, 3};
Matrix d{vec4, 3, 3};

TEST_CASE("Arithmetic Operators")
{

    // MULT:
    CHECK_THROWS(a * b);
    CHECK_THROWS(b * a);
    CHECK_THROWS(b * c);
    // CHECK(3*a);
    CHECK_NOTHROW(a * c);
    CHECK_NOTHROW(a *= 3);
    // ADD:
    CHECK_NOTHROW(-a);
    CHECK_NOTHROW(+a);
    CHECK_THROWS(a + b);
    CHECK_THROWS(b + c);
    CHECK_THROWS(b += c);
    CHECK_NOTHROW(b + d);
    // SUB:
    CHECK_THROWS(a - b);
    CHECK_THROWS(b - c);
    CHECK_THROWS(b -= c);
    CHECK_NOTHROW(b -= d);
    CHECK_NOTHROW(b - d);
    CHECK_THROWS(a - c);
}

TEST_CASE("Comparison Operators")
{
    CHECK(a != b);
    vector<double> vecop1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> vecop2 = {1, 2, 0, 1, 1, 1};
    Matrix e{vecop2, 3, 3};
    Matrix f{vecop1, 2, 3};
    CHECK((e > f) == true);
    CHECK((e >= f) == true);
    CHECK((d > c) == true);
    CHECK((d >= c) == true);
}

TEST_CASE("Increment Decrement Operators")
{
    vector<double> vec11 = {2, 1, 1, 2};
    Matrix aa{vec11, 2, 2};
    vector<double> vec12 = {1, 0, 0, 1};
    Matrix ab{vec12, 2, 2};
    CHECK((aa == ab++) == true); // need to fix to CHECK
    CHECK((aa-- == ab) == true); // need to fix to CHECK
}

TEST_CASE("mult")
{
    vector<double> vecm1 = {2, 1, 1, 2};
    vector<double> vecm2 = {4, 2, 2, 4};
    Matrix aa{vecm1, 2, 2};
    CHECK_NOTHROW(aa *= 2);
    CHECK(aa._vec == vecm2);
    CHECK_NOTHROW(aa * 3);
}
TEST_CASE("eql")
{
    vector<double> vecm1 = {20.9, 1, 1, 2};
    vector<double> vecm2 = {20.8, 1, 1, 2};
    Matrix aa{vecm1, 2, 2};
    Matrix ab{vecm2, 2, 2};
    CHECK(aa != ab);
}
