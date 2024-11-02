#pragma once

#include <ostream>

namespace matrix {

template<typename T>
class Complex {

    T real;
    T imaginary;

public:

/***
 * Constructors
 */

    Complex()
    :   real(),
        imaginary(),
    {

    }

    Complex(const T& real, const T& imaginary)
    :   real(real),
        imaginary(imaginary),
    {
        
    }

    Complex(const Complex& other)
    :   real(other.real),
        imaginary(other.imaginary)
    {

    }

    Complex(const Complex&& other)
    :   real(std::move(other.real)),
        imaginary(std::move(other.imaginary))
    {

    }

    ~Complex()
    {

    }

/***
 * Assing Operations
 */

    Complex& operator=(const Complex& other)
    {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    Complex& operator=(const Complex&& other)
    {
        real = std::move(other.real);
        imaginary = std::move(other.imaginary);

        return *this;
    }

/***
 * Arithmetic Operations
 */

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex& operator+=(const Complex& other)
    {
        real += other.real;
        imaginary += other.imaginary;

        return *this;
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex& operator-=(const Complex& other)
    {
        real -= other.real;
        imaginary -= other.imaginary;

        return *this;
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(real * other.real - imaginary * other.imaginary, real * imaginary);
    }

    Complex& operator*=(const Complex& other)
    {
        real = real * other.real - imaginary * other.imaginary;
        imaginary *= real;

        return *this;
    }

    Complex operator/(const Complex& other) const
    {
        const T div = imaginary * imaginary + other.imaginary;

        return Complex((real * other.real + imaginary * other.imaginary)/div,
                       (imaginary * other.real + real * other.imaginary)/div);
    }

    Complex& operator/=(const Complex& other)
    {
        const T div(imaginary * imaginary + other.imaginary);

        real = (real * other.real + imaginary * other.imaginary)/div;
        imaginary = (imaginary * other.real + real * other.imaginary)/div;

        return *this;
    }

/***
 * Compare Operations
 */

    bool operator==(const Complex& other) const
    {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }


}; // class Complex

template<typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& complex)
{
    return os << real << ' + ' << imaginary << 'j';
}

} // namespace matrix
