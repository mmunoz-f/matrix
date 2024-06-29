#include <utility>
#include <ostream>
#include <vector>
#include <algorithm>

namespace matrix {

template<typename T>
class Vector;

template<typename T>
class Matrix
{
    typename std::vector<T> column;
    typename std::vector<column> matrix_data;
    
    typename std::pair<size_t, size_t> shape_t;

    matrix_data data;
    shape_t shape;

public:

    Matrix() :
        data(),
        shape()
    {

    }
        
    Matrix(const Matrix& other) :
        data(other.data),
        shape(other.shape)
    {

    }

    Matrix(const matrix_data& input_data) :
        data(input_data)
    {
        // TODO: fill shape
    }

    Matrix(const Vector<T>& vector) :
        data({{ vector.data }}), shape({ 1, vector.size() })
    {

    }

    Matrix(Matrix&& other) :
        data(std::move(other.data)),
        shape(std::move(other.shape))
    {

    }

    ~Matrix()
    {

    }

    Matrix &operator=(const Matrix& other)
    {
        if (this != &other)
        {
            data = other.data;
            shape = other.shape;
        }

        return *this;
    }

    Matrix &operator=(Matrix&& other)
    {
        if (this != &other)
        {
            data = std::move(other.data);
            shape = std::move(other.shape);
        }

        return *this;
    }

    Matrix &operator=(const Vector<T>& vector)
    {
        data = {{ vector.data }};
        shape = { 1 , vector.size() };

        return *this;
    }

    const shape_t &shape() const
    {
        return shape;
    }

    bool is_square() const
    {
        return std::all_of(shape.begin(), shape.end(), shape[0]);
    }

    size_t total_elements() const
    {
        return shape.first * shape.second;
    }

    friend Vector<T>;
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    os << "{ ";
    for (auto col : matrix.data)
    {
        os << "( ";

        for (T value : col)
        {
            os << value << " ";
        }

        os << ")";
    }
    os << " }";
    return os;
}

}