#pragma once

#include <concepts>
#include <utility>
#include <array>
#include <ostream>
#include <cmath>

#include "utils.h"

namespace matrix {

template<typename T, size_t M, size_t N>
class Matrix;

template<typename T, size_t N>
class Vector
{

    std::array<T, N> _data;

public:

/***
 * Constructors
 */

    Vector()
    :   _data()
    {

    }

    Vector(std::same_as<T> auto ... init)
        requires (sizeof...(init) == N)
    :   _data{init ...}
    {

    }

    template <size_t O, size_t P>
    Vector(const Matrix<T, O, P>& matrix)
        requires (O * P == N)
    :   _data(matrix._data)
    {

    }

/***
 * Assign operations
 */


    Vector& operator=(std::same_as<T> auto ... init)
        requires (sizeof...(init) == N)
    {
        _data = {init ...};

        return *this;
    }

    template<size_t O, size_t P>
    Vector& operator=(const Matrix<T, O, P>& matrix)
        requires (O * P == N)
    {
        _data = matrix._data;

        return *this;
    }

    

/***
 * Arithmetics operations
 */

    Vector operator+(const Vector& other) const
    {
        Vector vector;

        for (size_t i = 0; i < size(); i++)
        {
            vector[i] = _data[i] + other[i];
        }

        return vector;
    }

    Vector& operator+=(const Vector& other)
    {
        for (size_t i = 0; i < size(); i++)
        {
            _data[i] += other[i];
        }

        return *this;
    }

    Vector operator-(const Vector& other) const
    {
        Vector vector;
        
        for (size_t i = 0; i < size(); i++)
        {
            vector[i] = _data[i] - other[i];
        }

        return vector;
    }

    Vector& operator-=(const Vector& other)
    {
        for (size_t i = 0; i < size(); i++)
        {
            _data[i] -= other[i];
        }

        return *this;
    }

    template<typename S>
    auto operator*(const S& scalar) const
    -> Vector<decltype(std::declval<T>() * std::declval<S>()), N>
    {
        Vector vector;

        for (size_t i = 0; i < size(); i++)
        {
            vector[i] = _data[i] * scalar;

            if (vector[i] == 0) // TODO Cause sometimes -0.0f :)
                vector[i] = 0;
        }

        return vector;
    }

    template<typename S>
    Vector& operator*=(const S& scalar)
    {
        for (size_t i = 0; i < size(); i++)
        {
            _data[i] *= scalar;
        }

        return *this;
    }

    constexpr size_t size() const
    {
        return _data.size();
    }

    inline const T& operator[](size_t pos) const
    {
        return _data[pos];
    }

    inline T&  operator[](size_t pos)
    {
        return _data[pos];
    }

    T dot(const Vector& other) const
    {
        T result = T();

        for (size_t i = 0; i < size(); i++)
        {
            result = std::fma(_data[i], other[i], result);
        }

        return result;
    }

    T norm_1() const
    {
        T result = T();

        for (size_t i = 0; i < size(); i++)
        {   
            result += _data[i];
        }

        return result;
    }

    float norm() const
    {
        float result = 0.f;

        for (size_t i = 0; i < size(); i++)
        {
            result = std::fma(_data[i], _data[i], result);
        }

        return std::pow(result, 0.5f);
    }

    T norm_inf() const
    {
        T max = abs(_data[0]);

        for (size_t i = 1; i < size(); i++)
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
        return _data == other._data;
    }

    inline bool operator!=(const Vector& other) const
    {
        return _data != other._data;
    }

    template<typename t, size_t m, size_t n>
    friend class Matrix;

    template<typename t, size_t n>
    friend std::ostream& operator<<(std::ostream& os, const Vector<t, n>& vector);
}; // Class Vector

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vector)
{
    os << "( ";
    
    for (T value : vector._data)
    {
        os << value << " ";
    }

    os << ")";
    return os;
}

template<typename T, size_t N>
Vector<T, N> operator*(const T& scalar, const Vector<T, N>& vector)
{
    return vector * scalar;
}

template<typename T, typename S, size_t N, size_t M>
Vector<T, N> linear_combination(const Vector<Vector<T, N>, M>& vectors, const Vector<S, M>& coefs)
{
    Vector<T, N> result;
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            result[i] = std::fma(vectors[j][i], coefs[j], result[i]);
        }
    }

    return result;
}

template<typename T, size_t N>
inline Vector<T, N> lerp(const Vector<T, N>& u, const Vector<T, N>& v, const float scalar)
{
    return linear_combination(Vector<Vector<T, N>, 2>({u, v}), Vector<float, 2>({1 - scalar, scalar}));
}

template<typename T, size_t N>
inline T   angle_cos(const Vector<T, N>& u, const Vector<T, N>& v)
{
    return u.dot(v) / (u.norm() * v.norm());
}

template<typename T>
Vector<T, 3> cross_product(const Vector<T, 3>& u, const Vector<T, 3>& v)
{
    Vector<T, 3> result({
        -(v[1] * u[2]),
        -(u[0] * v[2]),
        -(u[1] * v[0])
    });
    result[0] = std::fma(u[1], v[2], result[0]);
    result[1] = std::fma(u[2], v[0], result[1]);
    result[2] = std::fma(u[0], v[1], result[2]);

    return result;
}

} // namespace matrix