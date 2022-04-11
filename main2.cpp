
/*
 @AUTHOR: dvir borochov
 how to run:
  clang++-9 main2.cpp -o main
   */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main()
{

    std::vector<double> identity1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};

    Matrix a{identity1, 3, 3};
    Matrix b{identity2, 3, 3}; 
    Matrix c{identity3, 3, 3};
    
    cout << a << endl;

    cout << (-a) << endl;

    cout << (3 * a * 3) << endl;

    a *= -3; //changes the orginal mat

    cout << (a + b) << endl; // prints the 0 matrix
    cout << (b - a) << endl;

    cout << (b * a) << endl;

    cout << (b *= a) << endl;



    cout << "End of demo!" << endl;
    return 0;
}
