//
// @AUTHOR: dvir borochov
// Header file for class Matrix

namespace zich
{
    class Matrix
    {
        int _row;
        int _column;

    public:
        Matrix();
        Matrix(std::vector<double> vec, int row, int column);

        //-----------------------------
        // Arithmetic Operators
        //-----------------------------

        Matrix operator-();
        Matrix operator-(const Matrix &mat);
        Matrix operator-=(const Matrix &mat);

        Matrix operator+() const;
        Matrix operator+(const Matrix &mat);
        Matrix operator+=(const Matrix &mat);

        Matrix operator*=(double d);

        //-----------------------------
        // Comparison Operators
        //-----------------------------

        bool operator!=(const Matrix &other) const;

        bool operator==(const Matrix &other) const;

        bool operator<=(const Matrix &other) const;
        bool operator>=(const Matrix &other) const;

        bool operator<(const Matrix &other) const;
        bool operator>(const Matrix &other) const;

        //-----------------------------
        // Increment Decrement Operators
        //-----------------------------
////////////////////////////////////////  zich::Matrix zich::Matrix::operator*(zich::Matrix &mat)

       // Matrix &operator--();
        Matrix operator--(int);

      //  Matrix &operator++();
        Matrix operator++(int);

        //-----------------------------
        // Friend Operators
        //-----------------------------

        friend Matrix operator*(double d, Matrix &mat);
         Matrix operator*(Matrix &mat);

        //-----------------------------
        // I/O Operators
        //-----------------------------
        friend std::ostream &operator<<(std::ostream &out, Matrix mat);
        friend std::istream &operator>>(std::istream &in, Matrix &mat);
    };

}