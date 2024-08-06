#pragma once

#include <utility>
#include <vector>
#include <ostream>

namespace matrix {

template<typename T>
class Vector;

template<typename T>
class Matrix
{
    typedef std::vector<T> matrix_data;
    
    typedef std::pair<size_t, size_t> shape_t;

    matrix_data _data;
    shape_t _shape;

public:

/***
 * Constructors
 */

    Matrix() :
        _data(),
        _shape()
    {

    }

    Matrix(const shape_t& shape, const T& value = T()) :
        _data(shape.first * shape.second, value),
        _shape(shape)
    {

    }

    Matrix(const Matrix& other) :
        _data(other._data),
        _shape(other._shape)
    {

    }

    Matrix(std::initializer_list<std::initializer_list<T> > init) :
        _data(),
        _shape()
    {
        _shape.first = init.size();
        if (_shape.first > 0)
            _shape.second = init.begin()->size();
        else
            _shape.second = 0;

        _data.reserve(_shape.first * _shape.second);
        for (auto row : init)
        {
            if (row.size() != _shape.second)
                throw std::runtime_error(
                    "Matrix initializer list constructor: not all nodes had the same size"
                );

            _data.insert(_data.end(), row);
        }
    }

    Matrix(const Vector<T>& vector) :
        _data(vector._data),
        _shape(1, vector.size())
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

/***
 * Assign operations
 */

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            _data = other._data;
            _shape = other._shape;
        }

        return *this;
    }

    Matrix& operator=(std::initializer_list<std::initializer_list<T> > init)
    {
        _shape.first = init.size();
        if (_shape.first > 0)
            _shape.second = init.begin()->size();
        else
            _shape.second = 0;

        _data.clear();
        _data.reserve(_shape.first * _shape.second);
        for (auto row : init)
        {
            if (row.size() != _shape.second)
                throw std::runtime_error(
                    "Matrix initializer list constructor: not all nodes had the same size"
                );

            _data.insert(_data.end(), row);
        }

        return *this;
    }

    Matrix& operator=(const Vector<T>& vector)
    {
        _data = vector._data;
        _shape = ( 1 , vector.size() );

        return *this;
    }

/***
 * Move operations
 */

    Matrix& operator=(Matrix&& other)
    {
        if (this != &other)
        {
            _data = std::move(other._data);
            _shape = std::move(other._shape);
        }

        return *this;
    }

/***
 * Access methods
 */

    inline const T& operator()(size_t i, size_t j) const
    {
        return _data[i * _shape.second + j];
    }

    inline T& operator()(size_t i, size_t j)
    {
        return _data[i * _shape.second + j];
    }

    const Vector<T> operator[](size_t pos) const
    {
        Vector<T> row(_shape.second);

        for (size_t i = 0; i < _shape.second; i++)
        {
            row[i] = (*this)(pos, i);
        }

        return row;
    }

    const Vector<T> col(size_t pos) const
    {
        Vector<T> col(_shape.first);

        for (size_t i = 0; i < _shape.first; i++)
        {
            col[i] = (*this)(i, pos);
        }

        return col;
    }

    void change_row(size_t row_index, const Vector<T>& row)
    {
        if (row.size() != _shape.second)
            throw std::runtime_error(
                "Matrix change_row: new row had not correct size"
            );

        for (size_t i = 0; i < _shape.second; i++)
        {
            (*this)(row_index, i) = row[i];
        }
    }

    void change_col(size_t col_index, const Vector<T>& col)
    {
        if (col.size() != _shape.first)
            throw std::runtime_error(
                "Matrix change_col: new col had not correct size"
            );

        for (size_t i = 0; i < _shape.first; i++)
        {
            (*this)(i, col_index) = col[i];
        }
    }

    inline const shape_t &shape() const
    {
        return _shape;
    }

    inline bool is_square() const
    {
        return _shape.first == _shape.second;
    }

    inline size_t total_elements() const
    {
        return _shape.first * _shape.second;
    }

    T trace() const
    {
        if (!is_square())
            throw std::runtime_error(
                "trace: matrix is not square"
            );

        T result = T();

        for (size_t i = 0; i < _shape.first; i++)
        {
            result += (*this)(i, i);
        }

        return result;
    }

/***
 * Arithmetic operations
 */

    Matrix operator+(const Matrix& other) const
    {
        Matrix matrix(shape());

        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                matrix(i, j) = (*this)(i, j) + other(i, j);
            }

        return matrix;
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                (*this)(i, j) += other(i, j);
            }

        return *this;
    }

    Matrix operator-(const Matrix& other) const
    {
        Matrix matrix(shape());

        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                matrix(i, j) = (*this)(i, j) - other(i, j);
            }

        return matrix;
    }

    Matrix& operator-=(const Matrix& other)
    {
        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                (*this)(i, j) -= other(i, j);
            }

        return *this;
    }

    Matrix operator*(const T& scalar) const
    {
        Matrix matrix(shape());

        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                matrix(i, j) = (*this)(i, j) * scalar;
            }

        return matrix;
    }

    Matrix& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < shape().first; i++)
            for (size_t j = 0; j < shape().second; j++)
            {
                (*this)(i, j) *= scalar;
            }

        return *this;
    }

    Vector<T> operator*(const Vector<T>& u) const
    {
        const size_t dim = u.size();
        if (_shape.second != dim) // TODO: check in comp time
            throw std::runtime_error(
                "matrix*vector multiplication: invalid multiplication, check dims of both object"
            );

        Vector<T> result(_shape.first);

        for (size_t i = 0; i < _shape.first; i++)
        {
            result[i] = u.dot(_data[i]);
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const
    {
        if (_shape.second != other.shape().first) // TODO: check in comp time
            throw std::runtime_error(
                "matrix*matrix multiplication: invalid multiplication, check dims of both object"
            );

        Matrix<T> result(shape_t(_shape.first, other.shape().second));

        for (size_t i = 0; i < _shape.first; i++)
            for (size_t j = 0; j < other.shape().second; j++)
            {
                result(i, j) = _data[i].dot(other.col(j));
            }

        return result;
    }

/***
 * Equality operations
 */

    bool operator==(const Matrix& other) const
    {
        if (_shape != other._shape)
            return false;

        for (size_t i = 0; i < _shape.first; i++)
            for (size_t j = 0; j < _shape.second; j++)
                if ((*this)(i, j) != other(i, j))
                    return false;

        return true;
    }

    inline bool operator!=(const Matrix& other) const
    {
        return !(*this == other);
    }

    friend Vector<T>;

    template<typename t>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<t>& matrix);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    os << "{ ";

    for (size_t i = 0; i < matrix._shape.first; i++)
    {
        os << "( ";

        for (size_t j = 0; j < matrix._shape.second; j++)
        {
            os << matrix(i, j) << " ";
        }

        os << ") ";
    }
    
    os << "}";

    os << " (" << matrix._shape.first << "x" << matrix._shape.second << ")";
    return os;
}

template<typename T>
Matrix<T> operator*(const T scalar, const Matrix<T>& matrix)
{
    return matrix * scalar;
}

template<typename T>
inline Matrix<T> lerp(const Matrix<T>& a, const Matrix<T>& b, const float scalar)
{
    Matrix<T> result(a.shape());
    const Vector<float> coefs({1 - scalar, scalar});

    for (size_t i = 0; i < result.shape().first; i++)
    {
        result.change_row(i, linear_combination<float>(Vector<Vector<T> >{a[i], b[i]}, coefs));
    }

    return result;
}

}