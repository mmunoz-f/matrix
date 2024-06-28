#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>

namespace matrix {

template<typename T>
class Vector;

template<typename T>
class Matrix
{
    typename std::vector<T> column;
    typename std::vector<column> matrix_data;
    
    typename std::vector<size_t> shape_t;

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
        return std::accumulate(shape.begin(), shape.end(), 1,
            [](size_t acc, size_t i) { return acc * i })
    }

    friend Vector<T>;
};

}