//
// @AUTHOR: dvir borochov
// Header file for class Matrix

namespace zich
{
    class Matrix
    {
        std::vector<double> _vec;
        int _row;
        int _column;

    public:
        Matrix(std::vector<double> vec, int row, int column);

        //-----------------------------
        // Arithmetic Operators
        //-----------------------------

        Matrix operator-();
        Matrix operator-(const Matrix &other);
        Matrix operator-=(const Matrix &other);

        Matrix operator+() const;
        Matrix operator+(const Matrix &other);
        Matrix operator+=(const Matrix &other);

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

        // Matrix &operator--();
        Matrix operator--(int num);

        //  Matrix &operator++();
        Matrix operator++(int num);

        //-----------------------------
        // Friend Operators
        //-----------------------------
        friend Matrix operator*(double d, Matrix &mat);
        Matrix operator*(Matrix &other);

        //-----------------------------
        // I/O Operators
        //-----------------------------
        friend std::ostream &operator<<(std::ostream &out, Matrix mat);
        friend std::istream &operator>>(std::istream &in, Matrix &mat);
    };

}