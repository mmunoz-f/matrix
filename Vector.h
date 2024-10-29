#pragma once

#include <concepts>
#include <utility>
#include <type_traits>
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

    Vector(const Vector& other)
    :   _data(other._data)
    {

    }

    Vector(Vector&& other)
    :   _data(std::move(other._data))
    {

    }

    template <size_t O, size_t P>
    Vector(const Matrix<T, O, P>& matrix)
        requires (O * P == N)
    :   _data(matrix._data)
    {

    }

    ~Vector()
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

    Vector& operator=(const Vector& other)
    {
        _data = other._data;

        return *this;
    }

    Vector& operator=(Vector&& other)
    {
        _data = std::move(other._data);

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

        for (size_t i = 0; i < N; i++)
        {
            vector[i] = _data[i] + other[i];
        }

        return vector;
    }

    Vector& operator+=(const Vector& other)
    {
        for (size_t i = 0; i < N; i++)
        {
            _data[i] += other[i];
        }

        return *this;
    }

    Vector operator-(const Vector& other) const
    {
        Vector vector;
        
        for (size_t i = 0; i < N; i++)
        {
            vector[i] = _data[i] - other[i];
        }

        return vector;
    }

    Vector& operator-=(const Vector& other)
    {
        for (size_t i = 0; i < N; i++)
        {
            _data[i] -= other[i];
        }

        return *this;
    }

    Vector operator*(const T& scalar) const
    {
        Vector vector;

        for (size_t i = 0; i < N; i++)
        {
            vector[i] = _data[i] * scalar;
        }

        return vector;
    }

    Vector& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < N; i++)
        {
            _data[i] *= scalar;
        }

        return *this;
    }

    Vector operator/(const T& scalar) const
    {
        Vector vector;

        for (size_t i = 0; i < N; i++)
        {
            vector[i] = _data[i] / scalar;
        }
    
        return vector;
    }

    Vector& operator/=(const T& scalar)
    {
        for (size_t i = 0; i < N; i++)
        {
            _data[i] /= scalar;
        }

        return *this;
    }

    constexpr size_t size() const
    {
        return N;
    }

    inline const T& operator[](size_t pos) const
    {
        return _data[pos];
    }

    inline T&  operator[](size_t pos)
    {
        return _data[pos];
    }

    template<typename U>
    auto dot(const Vector<U, N>& other) const
    -> decltype(std::declval<T>() * std::declval<U>())
        requires (std::is_arithmetic<T>::value)
    {
        T result = T();

        for (size_t i = 0; i < N; i++)
        {
            result = std::fma(_data[i], other[i], result);
        }

        return result;
    }

    template<typename U>
    auto dot(const Vector<U, N>& other) const
    -> decltype(std::declval<T>() * std::declval<U>())
        requires (!std::is_arithmetic<T>::value)
    {
        T result = T();

        for (size_t i = 0; i < N; i++)
        {
            result += _data[i] * other[i];
        }

        return result;
    }

    float norm_1() const
        requires (std::is_arithmetic<T>::value)
    {
        float result = 0.0f;

        for (size_t i = 0; i < N; i++)
        {   
            result += _data[i];
        }

        return result;
    }

    float norm() const
        requires (std::is_arithmetic<T>::value)
    {
        float result = 0.0f;

        for (size_t i = 0; i < N; i++)
        {
            result = std::fma(_data[i], _data[i], result);
        }

        return std::pow(result, 0.5f);
    }

    // TODO overload norm for complex numbers

    float norm_inf() const
        requires (std::is_arithmetic<T>::value)
    {
        float max = 0.0f;

        for (size_t i = 0; i < N; i++)
        {
            max = std::max(max, static_cast<float>(abs(_data[i])));
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

template<typename T>
struct is_vector : std::false_type {};

template<typename T, size_t N>
struct is_vector<Vector<T, N>> : std::true_type {};

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

template<typename T, size_t N, typename S>
Vector<T, N> operator*(const S& scalar, const Vector<T, N>& vector)
{
    return vector * scalar;
}

template<typename object, typename scalar, size_t N>
inline object linear_combination(const Vector<object, N>& elements, const Vector<scalar, N>& coefs)
    requires (!matrix::is_vector<object>::value || !std::is_arithmetic<object>::value)
{
    return elements.dot(coefs);
}

template<typename T, size_t N, typename scalar, size_t M>
Vector<T, N> linear_combination(const Vector<Vector<T, N>, M>& elements, const Vector<scalar, M>& coefs)
    requires (std::is_arithmetic<T>::value)
{
    Vector<T, N> result;
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            result[i] = std::fma(elements[j][i], coefs[j], result[i]);
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
    requires (std::is_arithmetic<T>::value)
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

template<typename T>
Vector<T, 3> cross_product(const Vector<T, 3>& u, const Vector<T, 3>& v)
    requires (!std::is_arithmetic<T>::value)
{
    Vector<T, 3> result({
        -(v[1] * u[2]),
        -(u[0] * v[2]),
        -(u[1] * v[0])
    });
    result[0] += u[1] * v[2];
    result[1] += u[2] * v[0];
    result[2] += u[0] * v[1];

    return result;
}

} // namespace matrix
