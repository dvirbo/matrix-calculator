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
Matrix b{vec1, 3, 3};
Matrix c{vec3, 2, 3};
Matrix d{vec4, 3, 3};

TEST_CASE("Arithmetic Operators")
{

    // MULT:
    CHECK_THROWS(a * b);
    CHECK_THROWS(b * a);
    CHECK_NOTHROW(b * c);
    CHECK_NOTHROW(a * c);
    CHECK_NOTHROW(a *= 3);
    // ADD:
    CHECK_NOTHROW(-a);
    CHECK_NOTHROW(+a);
    CHECK_THROWS(a + b);
    CHECK_NOTHROW(b + c);
    CHECK_NOTHROW(b += c);

    // SUB:
    CHECK_THROWS(a - b);
    CHECK_NOTHROW(b - c);
    CHECK_NOTHROW(b -= c);
}

TEST_CASE("Comparison Operators")
{
    CHECK(a != b);
    Matrix e{vec4, 3, 3};
    CHECK(d == e);
    CHECK(a < b);
    CHECK(a <= b);
    CHECK(d > c);
    CHECK(d >= c);
}

// TEST_CASE("Increment Decrement Operators")
// {
//     vector<double> vec11 = {2, 0, 0, 2};
//     Matrix aa{vec11, 2, 2};
//     vector<double> vec12 = {1, 0, 0, 1};
//     Matrix ab{vec12, 2, 2};
//     CHECK(aa--);
//     CHECK(aa == ab);
//     CHECK(ab++);
//     CHECK(aa++);
//     CHECK(aa == ab);
// }
