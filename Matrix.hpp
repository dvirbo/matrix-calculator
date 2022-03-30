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
        Matrix(std::vector<double> vec, int row, int column);

        //-----------------------------
        // Arithmetic Operators
        //-----------------------------

        Matrix operator-() const;
        Matrix operator-(const Matrix &num);
        Matrix operator-=(const Matrix &num);

        Matrix operator+() const;
        Matrix operator+(const Matrix &num);
        Matrix operator+=(const Matrix &num);

        Matrix operator*=(double d) const;

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

        Matrix &operator--();
        Matrix operator--(int dummy);

        Matrix &operator++();
        Matrix operator++(int dummy);

        //-----------------------------
        // Friend Operators
        //-----------------------------

        friend Matrix operator*(double d, const Matrix &num);

        //-----------------------------
        // I/O Operators
        //-----------------------------
        friend std::ostream &operator<<(std::ostream &out, Matrix num);
        friend std::istream &operator>>(std::istream &in, Matrix &num);
    };

}