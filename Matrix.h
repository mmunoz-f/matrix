template<type T, size N, size M>
class Matrix
{
    template<size N, size M>
    class Shape()
    {
        Shape(size_t N, size_t M);
    };

    Matrix(const Matrix& other);

    Matrix &operator=(const Matrix& other);

public:
    shape()
};