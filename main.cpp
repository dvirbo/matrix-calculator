#include "Matrix.cpp"

/*
 @AUTHOR: dvir borochov
 how to run: 
  clang++-9 main.cpp -o main
   */

int main()
{

    vector<double> fvec = {11, 0, 0, 0, 11, 0, 0, 0, 11};
    vector<double> svec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> tvec = {-1, 2, -3, 0, 0, 4, 1, 0, -1};
    vector<double> l1vec = {1,0,0,1};
    vector<double> l2vec = {3,2,4,3};

    Matrix a{fvec, 3, 3}; // constructor taking a vector and a matrix size
    Matrix b{svec, 3, 3}; // constructor taking a vector and a matrix size
    Matrix c{tvec, 3, 3}; // constructor taking a vector and a matrix size
    Matrix d1{l1vec, 2, 2}; // constructor taking a vector and a matrix size
    Matrix d2{l2vec, 2, 2}; // constructor taking a vector and a matrix size
    bool ans = true;
    cout << a << endl;
    /* prints [11 0 0]
              [0 11 0]
              [0 0 11]*/

    cout << (a++) << endl;
    /* prints [12 1 1]
              [1 12 1]
              [1 1 12]*/

    cout << (a += b) << endl;
    /*
    [12 2 3]
    [4 16 6]
    [7 8 20]
             */

    cout << (b * a) << endl;
    /*
    [25 62 147]
    [120 105 0]
    [0   0   0]*/

    a *= -1; // change the real matrix:

    cout << (a + b) << endl;
    /*
    [-11 0 0]
    [0 -11 0]
    [0 0 -11]*/

    cout << (b - a) << endl;
    /*
    [13 4 6]
    [8 21 12]
    [14 16 29]*/


    cout << (a < b) << endl; // print 0

    cout << (d1 *= d2) << endl;

    cout << "End of main!" << endl;
    return 0;
}
