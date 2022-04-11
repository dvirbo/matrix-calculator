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

    Matrix a{fvec, 3, 3}; // constructor taking a vector and a matrix size
    Matrix b{svec, 3, 3}; // constructor taking a vector and a matrix size
    Matrix c{tvec, 3, 3}; // constructor taking a vector and a matrix size

    cout << a << endl;

    cout << (a++) << endl;

    cout << (a += b) << endl;

    cout << (b * a) << endl;

    a *= -1; // change the real matrix:

    cout << (a + b) << endl;

    cout << (b - a) << endl;

    vector<double> l1vec = {1, 2, 3, 1};
    vector<double> l2vec = {3, 2, 4, 3};
    Matrix d1{l1vec, 2, 2}; // constructor taking a vector and a matrix size
    Matrix d2{l2vec, 2, 2}; // constructor taking a vector and a matrix size

   // cout << (d1 * d2) << endl;
   // cout << (d2 * d1) << endl;
   // cout << (d1 *= d2) << endl;
   // cout << (d2 *= d1) << endl;

    cout << "End of main!" << endl;
    return 0;
}
