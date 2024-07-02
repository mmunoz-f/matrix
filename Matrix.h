#include <utility>
#include <ostream>
#include <vector>

namespace matrix {

template<typename T>
class Vector;

template<typename T>
class Matrix
{
    typedef std::vector<T> column;
    typedef std::vector<column> matrix_data;
    
    typedef std::pair<size_t, size_t> shape_t;

    matrix_data _data;
    shape_t _shape;

public:

    Matrix() :
        _data(),
        _shape()
    {

    }
        
    Matrix(const Matrix& other) :
        _data(other._data),
        _shape(other._shape)
    {

    }

    Matrix(const matrix_data& input_data) :
        _data(input_data), _shape()
    {
        _shape.first = _data.size();
        if (_shape.first > 0)
            _shape.second = _data[0].size(); 
    }

    Matrix(const Vector<T>& vector) :
        _data({{ vector._data }}), _shape({ 1, vector.size() })
    {

    }

    Matrix(Matrix&& other) :
        _data(std::move(other._data)),
        _shape(std::move(other._shape))
    {

    }

    ~Matrix()
    {

    }

    Matrix &operator=(const Matrix& other)
    {
        if (this != &other)
        {
            _data = other._data;
            _shape = other._shape;
        }

        return *this;
    }

    Matrix &operator=(Matrix&& other)
    {
        if (this != &other)
        {
            _data = std::move(other._data);
            _shape = std::move(other._shape);
        }

        return *this;
    }

    Matrix &operator=(const Vector<T>& vector)
    {
        _data = {{ vector._data }};
        _shape = { 1 , vector.size() };

        return *this;
    }

    const shape_t &shape() const
    {
        return _shape;
    }

    bool is_square() const
    {
        return _shape.first == _shape.second;
    }

    size_t total_elements() const
    {
        return _shape.first * _shape.second;
    }

    friend Vector<T>;

    template<typename t>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    os << "{ ";

    for (auto col : matrix._data)
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