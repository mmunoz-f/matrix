#pragma once

#include <cmath>

#include <utility>
#include <array>
#include <ostream>

namespace matrix {

template<typename T, size_t N>
class Vector;

template<typename T, size_t M, size_t N>
class Matrix
{
public:
    struct Shape;

private:

    static constexpr Shape _shape = Shape(M, N);

    std::array<T, M*N> _data;

public:

/***
 * Constructors
 */

    Matrix()
    :   _data()
    {

    }

    Matrix(std::same_as<T> auto ... init)
        requires (sizeof...(init) == M*N)
    :   _data{init ...}
    {

    }

    Matrix(const Matrix& other)
    :   _data(other._data)
    {

    }

    Matrix(Matrix&& other)
    :   _data(std::move(other._data))
    {

    }

    template <size_t O>
    Matrix(const Vector<T, O>& vector)
        requires ((O / N == M) && (O % N == 0))
    :   _data(vector._data)
    {

    }

    ~Matrix()
    {

    }

/***
 * Assign operations
 */

    Matrix& operator=(std::same_as<T> auto ... init)
        requires (sizeof...(init) == M*N)
    {
        _data = {init ...};

        return *this;
    }

    Matrix& operator=(const Matrix& other)
    {
        _data = other._data;

        return *this;
    }

    Matrix& operator=(Matrix&& other)
    {
        _data = std::move(other._data);

        return *this;
    }

    template <size_t O>
    Matrix& operator=(const Vector<T, O>& vector)
        requires ((O / N == M) && (O % N == 0))
    {
        _data = vector._data;

        return *this;
    }

/***
 * Access methods
 */

    inline const T& operator()(size_t i, size_t j) const
    {
        return _data[i * _shape.n + j];
    }

    inline T& operator()(size_t i, size_t j)
    {
        return _data[i * _shape.n + j];
    }

    const Vector<T, N> row(size_t pos) const
    {
        Vector<T, N> row;

        for (size_t i = 0; i < N; i++)
        {
            row[i] = (*this)(pos, i);
        }

        return row;
    }

    const Vector<T, M> col(size_t pos) const
    {
        Vector<T, M> col;

        for (size_t i = 0; i < M; i++)
        {
            col[i] = (*this)(i, pos);
        }

        return col;
    }

    void change_row(size_t row_index, const Vector<T, N>& row)
    {
        for (size_t i = 0; i < N; i++)
        {
            (*this)(row_index, i) = row[i];
        }
    }

    void change_col(size_t col_index, const Vector<T, M>& col)
    {
        for (size_t i = 0; i < M; i++)
        {
            (*this)(i, col_index) = col[i];
        }
    }

    inline static constexpr const Shape &shape()
    {
        return _shape;
    }

    constexpr bool is_square() const
    {
        return M == N;
    }

    constexpr size_t total_elements() const
    {
        return M * N;
    }

    T trace() const
        requires (M == N)
    {
        T result = T();

        for (size_t i = 0; i < M; i++)
        {
            result += (*this)(i, i);
        }

        return result;
    }

    Matrix<T, N, M> traspose() const
    {
        Matrix<T, N, M> result;

        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
            {
                result(i, j) = (*this)(j, i);
            }

        return result;
    }

private:

    void swap_row(size_t a, size_t b)
    {
        Vector<T, N> tmp = row(a);
        change_row(a, row(b));
        change_row(b, tmp);
    }

    std::pair<bool, std::pair<size_t, size_t> > push_down_zeros(const size_t row_index, const size_t pivot)
    {
        if ((*this)(row_index, pivot) == 0)
        {
            for (size_t i = row_index + 1; i < M; i++)
                if ((*this)(i, pivot) != 0)
                {
                    swap_row(row_index, i);
                    return std::pair(true, std::pair(row_index, i));
                }
        }
        return std::pair(false, std::pair(0, 0));
    }

    T   make_pivot_one(const size_t row_index, const size_t pivot)
    {
        if ((*this)(row_index, pivot) == 1)
            return 1;

        T div = (*this)(row_index, pivot);
        
        change_row(row_index, row(row_index) / div);
        return div;
    }

public:

    void to_row_echelon()
    {
        size_t pivot = 0, i = 0;
        while (i < M && pivot < N)
        {
            push_down_zeros(i, pivot);
            
            if ((*this)(i, pivot) != 0)
            {
                make_pivot_one(i, pivot);
                for (size_t j = 0; j < M; j++) // Substract lines by pivot line * first not null elm of current line
                    if (j != i)
                        change_row(j, row(j) - (row(i)) * (*this)(j, pivot));
                i++;
            }

            pivot++;
        }
    }

    Matrix row_echelon() const
    {
        Matrix result = Matrix(*this);
        result.to_row_echelon();
        return result;
    }

    T determinant() const
        requires (M == N)
    {
        T result = 1;
        Matrix copy(*this);

        size_t i = 0, pivot = 0;
        while (i < M && pivot < N)
        {
            if (copy.push_down_zeros(i, pivot).first)
                result *= -1; // Change sign if rows are changed, cause math

            if ((*this)(i, pivot) != 0)
            {
                for (size_t j = i + 1; j < M; j++) // Substract lines by pivot line * first not null elm of current line
                    copy.change_row(j, copy.row(j) - copy.row(i) * (copy(j, pivot) / copy(i, pivot)));
                i++;
            }

            pivot++;
        }

        for (size_t i = 0; i < M; i++)
            result *= copy(i, i);

        return result;
    }

private:
    static constexpr Matrix generate_identity()
    {
        Matrix matrix;

        for (size_t i = 0; i < M; i++)
            matrix(i, i) = 1;

        return matrix;
    }

public:
    static Matrix identity()
    {
        static Matrix identity = generate_identity();

        return identity;
    }

    Matrix inverse() const
        requires (M == N)
    {
        Matrix copy(*this);
        Matrix inverse(Matrix::identity());

        size_t i = 0, pivot = 0;
        while (i < M && pivot < N)
        {
            auto swap_res = copy.push_down_zeros(i, pivot);
            if (swap_res.first)
                inverse.swap_row(swap_res.second.first, swap_res.second.second);

            if (copy(i, pivot) != 0)
            {
                T val = copy.make_pivot_one(i, pivot);
                if (val != 1)
                    inverse.change_row(i, inverse.row(i) / val);

                for (size_t j = 0; j < M; j++) // Substract lines by pivot line * first not null elm of current line
                    if (j != i)
                    {
                        T val = copy(j, pivot);
                        copy.change_row(j, copy.row(j) - val * copy.row(i));
                        inverse.change_row(j, inverse.row(j) - val * inverse.row(i));
                    }
                i++;
            }
            else
                throw std::runtime_error("inverse: matrix is singular");

            pivot++;
        }

        return inverse;
    }

    size_t rank() const
    {
        const Matrix echelon_form = row_echelon();

        size_t rank = 0;
        for (; rank < M; rank++)
        {
            Vector<T, N> _row = echelon_form.row(rank);
            for (size_t i = 0; i < N; i++)
            {
                if (_row[i] != 0)
                    break;

                if (i == N - 1)
                    return rank;
            }
        }

        return rank;
    }

/***
 * Arithmetic operations
 */

    Matrix operator+(const Matrix& other) const
    {
        Matrix matrix;

        for (size_t i = 0; i < M * N; i++)
        {
            matrix._data[i] = this->_data[i] + other._data[i];
        }

        return matrix;
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (size_t i = 0; i < M * N; i++)
        {
            this->_data[i] += other._data[i];
        }

        return *this;
    }

    Matrix operator-(const Matrix& other) const
    {
        Matrix matrix;

        for (size_t i = 0; i < M * N; i++)
        {
            matrix._data[i] = this->_data[i] - other._data[i];
        }

        return matrix;
    }

    Matrix& operator-=(const Matrix& other)
    {
        for (size_t i = 0; i < M * N; i++)
        {
            this->_data[i] -= other._data[i];
        }

        return *this;
    }

    Matrix operator*(const T& scalar) const
    {
        Matrix matrix;

        for (size_t i = 0; i < M * N; i++)
        {
            matrix._data[i] = this->_data[i] * scalar;
        }

        return matrix;
    }

    Matrix& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < M * N; i++)
        {
            this->_data[i] *= scalar;
        }

        return *this;
    }

    Matrix operator/(const T& scalar) const
    {
        Matrix matrix;

        for (size_t i = 0; i < M * N; i++)
        {
            matrix._data[i] = this->_data[i] / scalar;
        }

        return matrix;
    }

    Matrix& operator/=(const T& scalar)
    {
        for (size_t i = 0; i < M * N; i++)
        {
            this->_data[i] /= scalar;
        }

        return *this;
    }

    Vector<T, M> operator*(const Vector<T, N>& u) const
    {
        Vector<T, M> result;

        for (size_t i = 0; i < M; i++)
        {
            result[i] = u.dot(row(i));
        }

        return result;
    }

    template<size_t O, size_t P>
    Matrix<T, M, P> operator*(const Matrix<T, O, P>& other) const
        requires (N == O)
    {
        Matrix<T, M, P> result;

        for (size_t i = 0; i < M; i++)
            for (size_t j = 0; j < other.shape().n; j++)
            {
                result(i, j) = row(i).dot(other.col(j));
            }

        return result;
    }

    /***
     * Equality operators
     */

    bool operator==(const Matrix& other) const
    {
        return _data == other._data;
    }

    bool operator!=(const Matrix& other) const
    {
        return _data != other._data;
    }

    template<typename t, size_t n>
    friend class Vector;

    template<typename t, size_t m, size_t n>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<t, m, n>& matrix);
}; // class Matrix

template<typename T, size_t M, size_t N>
struct Matrix<T, M, N>::Shape
{
    size_t m;
    size_t n;

    // TODO not being defined outside because of type deduction errors, check why and make better
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape)
    {
        os << "(" << shape.m << "x" << shape.n << ")";

        return os;
    }
}; // struct Matrix::Shape

/**
 * TODO check type deduction in templates
**

template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& os, const typename Matrix<T, M, N>::Shape& shape)
{
    os << "(" << shape.m << "x" << shape.n << ")";

    return os;
}
*/

template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& matrix)
{
    os << "{ ";

    for (size_t i = 0; i < matrix._shape.m; i++)
    {
        os << "( ";

        for (size_t j = 0; j < matrix._shape.n; j++)
        {
            os << matrix(i, j) << " ";
        }

        os << ") ";
    }
    
    os << "} ";

    os << matrix._shape;
    return os;
}

template<typename T, size_t M, size_t N>
Matrix<T, M, N> operator*(const T scalar, const Matrix<T, M, N>& matrix)
{
    return matrix * scalar;
}

template<typename T, size_t M, size_t N>
inline Matrix<T, M, N> lerp(const Matrix<T, M, N>& a, const Matrix<T, M, N>& b, const float scalar)
{
    Matrix<T, M, N> result;
    const Vector<float, 2> coefs({1 - scalar, scalar});

    for (size_t i = 0; i < result.shape().m; i++)
    {
        result.change_row(i, linear_combination<float>(Vector<Vector<T, N>, 2>{a.row(i), b.row(i)}, coefs));
    }

    return result;
}

} // namespace matrix
