#pragma once

#include <utility>
#include <vector>
#include <ostream>
#include <cmath>

#include "utils.h"

namespace matrix {

template<typename T>
class Matrix;

template<typename T>
class Vector
{
    typedef T value_type;

    typedef std::vector<T> vector_data;

    typedef typename vector_data::iterator iterator;
    typedef typename vector_data::const_iterator const_iterator;

    vector_data _data;

public:

/***
 * Constructors
 */

    Vector() :
        _data()
    {

    }

    explicit Vector(size_t size, const T& value = T()) :
        _data(size, value)
    {

    }

    Vector(const Vector& other) :
        _data(other._data)
    {

    }

    Vector(const vector_data& data) :
        _data(data)
    {

    }

    Vector(const std::initializer_list<T>& init) :
        _data(init)
    {

    }

    Vector(const Matrix<T>& matrix) :
        _data()
    {
        _data.reserve(matrix.total_elements());

        for (auto row : matrix._data)
            for (T value : row)
            {
                _data.push_back(value);
            }
    }

    template<class _itetator>
    Vector(const _itetator& begin, const _itetator& end)
    {
        _data = vector_data(begin, end);
    }

    Vector(Vector&& other) :
        _data(std::move(other._data))
    {

    }

    Vector(vector_data&& data) :
        _data(std::move(data))
    {

    }

    ~Vector()
    {

    }

/***
 * Assign operations
 */

    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            _data = other._data;
        }

        return *this;
    }

    Vector& operator=(const vector_data& data)
    {
        _data = data;

        return *this;
    }

    Vector& operator=(const std::initializer_list<T>& init)
    {
        _data = init;

        return *this;
    }

    Vector& operator=(const Matrix<T>& matrix)
    {
        _data.clear();
        _data.reserve(matrix.total_elements());

        for (auto row : matrix._data)
            for (T value : row)
            {
                _data.push_back(value);
            }
    }

/***
 * Move operations
 */

    Vector& operator=(Vector&& other)
    {
        if (this != &other)
        {
            _data = std::move(other._data);
        }

        return *this;
    }

    Vector& operator=(vector_data&& data)
    {
        _data = std::move(data);

        return *this;
    }

/***
 * Access methods
 */

    inline const T& operator[](size_t pos) const
    {
        return _data[pos];
    }

    inline T&  operator[](size_t pos)
    {
        return _data[pos];
    }

    inline size_t size() const
    {
        return _data.size();
    }

    inline const_iterator begin() const
    {
        return _data.begin();
    }

    inline iterator begin()
    {
        return _data.begin();
    }

    inline const_iterator end() const
    {
        return _data.end();
    }

    inline iterator end()
    {
        return _data.end();
    }

/***
 * Arithmetics operations
 */

    Vector operator+(const Vector& other) const
    {
        size_t dim = size();
        Vector vector(dim);
        
        for (size_t i = 0; i < dim; i++) // TODO: change to only make size one time or use literal when optimized
        {
            vector[i] = _data[i] + other[i];
        }

        return vector;
    }

    Vector& operator+=(const Vector& other)
    {
        size_t dim = size();

        for (size_t i = 0; i < dim; i++)
        {
            _data[i] += other[i];
        }

        return *this;
    }

    Vector operator-(const Vector& other) const
    {
        size_t dim = size();
        Vector vector(dim);
        
        for (size_t i = 0; i < dim; i++)
        {
            vector[i] = _data[i] - other[i];
        }

        return vector;
    }

    Vector& operator-=(const Vector& other)
    {
        size_t dim = size();

        for (size_t i = 0; i < dim; i++)
        {
            _data[i] -= other[i];
        }

        return *this;
    }

    Vector operator*(const T& scalar) const
    {
        size_t dim = size();
        Vector vector(dim);

        for (size_t i = 0; i < dim; i++)
        {
            vector[i] = _data[i] * scalar;
        }

        return vector;
    }

    Vector& operator*=(const T& scalar)
    {
        size_t dim = size();
        Vector vector(dim);

        for (size_t i = 0; i < dim; i++)
        {
            _data[i] *= scalar;
        }

        return *this;
    }

    T dot(const Vector& other) const
    {
        size_t dim = size();
        T result = T();

        for (size_t i = 0; i < dim; i++)
        {
            result = std::fma(_data[i], other[i], result);
        }

        return result;
    }

    T norm_1() const
    {
        T result = T();

        for (T val : _data)
        {   
            result += val;
        }

        return result;
    }

    float norm() const
    {
        size_t dim = size();
        float result = 0.f;

        for (size_t i = 0; i < dim; i++)
        {
            result = std::fma(_data[i], _data[i], result);
        }

        return std::pow(result, 0.5f);
    }

    T norm_inf() const
    {
        size_t dim = size();
        T max = abs(_data[0]);

        for (size_t i = 1; i < dim; i++)
        {
            max = std::max(max, abs(_data[i]));
        }

        return max;
    }

/***
 * Equality operators
 */

    bool operator==(const Vector& other) const
    {
        size_t dim = size();
        if (dim != other.size())
            return false;
        
        for (size_t i = 0; i < dim; i++)
        {
            if (_data[i] != other[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const Vector& other) const
    {
        return !(*this == other);
    }

    friend Matrix<T>;

    template<typename t>
    friend std::ostream& operator<<(std::ostream& os, const Vector<t>& vector);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector)
{
    os << "( ";
    
    for (T value : vector._data)
    {
        os << value << " ";
    }

    os << ")";
    return os;
}

template<typename T>
Vector<T> operator*(const T& scalar, const Vector<T>& vector)
{
    return vector * scalar;
}

template<typename T, class container1, class container2>
Vector<T> linear_combination(const container1& vectors, const container2& coefs) // TODO: check T and (container1&container2)::value_type, is the same in comp time
{
    const size_t n_coefs = coefs.size();

    if (n_coefs != vectors.size()) // TODO in comp time?
        throw std::runtime_error(
            "linear combination: number of coeficients and number of vectors do not match"
        );

    const size_t dim = vectors[0].size();
    Vector<T> result(dim);
    
    for (size_t i = 0; i < dim; i++)
    {
        for (size_t j = 0; j < n_coefs; j++)
        {
            result[i] = std::fma(vectors[j][i], coefs[j], result[i]);
        }
    }

    return result;
}

template<typename T>
inline Vector<T> lerp(const Vector<T>& u, const Vector<T>& v, const float scalar)
{
    return linear_combination<float>(Vector<Vector<T> >({u, v}), Vector<float>({1 - scalar, scalar}));
}

template<typename T>
inline T   angle_cos(const Vector<T>& u, const Vector<T>& v)
{
    return u.dot(v) / (u.norm() * v.norm());
}

template<typename T>
Vector<T> cross_product(const Vector<T>& u, const Vector<T>& v) // TODO: Check size to be only 3 in comp time
{
    if (u.size() != 3 || v.size() != 3)
        throw std::runtime_error(
            "cross product: dims of vectors must be 3"
        );

    Vector<T> result({
        -(v[1] * u[2]),
        -(u[0] * v[2]),
        -(u[1] * v[0])
    });
    result[0] = std::fma(u[1], v[2], result[0]);
    result[1] = std::fma(u[2], v[0], result[1]);
    result[2] = std::fma(u[0], v[1], result[2]);

    return result;
}

}