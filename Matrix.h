#pragma once

#include <utility>
#include <vector>
#include <ostream>

#define ASSER_MESSAGE_WRONG_DIM_INITIALIZATION(a, b, c, d) \


namespace matrix {

template<typename T, size_t N>
class Vector;

template<typename T, size_t M, size_t N>
class Matrix : public std::array<T, M * N>
{

public:

struct Shape
{
    static constexpr size_t M = M;
    static constexpr size_t N = N;
}

static constexpr Shape shape;

/***
 * Constructors
 */

    Matrix(std::array<std::array<T, N>, M> init) :
    {
        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                (*this)(i, j) = init[i][j];
            }
    }

    Matrix(std::initializer_list<>)

/***
 * Assign operations
 */

    Matrix& operator=(std::array<std::array<T, N>, M> init)
    {
        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                (*this)(i, j) = init[i][j];
            }

        return *this;
    }

/***
 * Access methods
 */

    inline const T& operator()(size_t i, size_t j) const
    {
        return data()[i * _shape.second + j];
    }

    inline T& operator()(size_t i, size_t j)
    {
        return _data[i * _shape.second + j];
    }

    const Vector<T, N> row(size_t pos) const
    {
        Vector<T, N> row();

        for (size_t i = 0; i < Shape::N; i++)
        {
            row[i] = (*this)(pos, i);
        }

        return row;
    }

    const Vector<T, M> col(size_t pos) const
    {
        Vector<T, M> col();

        for (size_t i = 0; i < Shape::M; i++)
        {
            col[i] = (*this)(i, pos);
        }

        return col;
    }

    void change_row(size_t row_index, const Vector<T, N>& row)
    {
        for (size_t i = 0; i < Shape::N; i++)
        {
            (*this)(row_index, i) = row[i];
        }
    }

    void change_col(size_t col_index, const Vector<T, M>& col)
    {
        for (size_t i = 0; i < Shape::M; i++)
        {
            (*this)(i, col_index) = col[i];
        }
    }

    constexpr Shape &shape() const // Todo check if Shape is instanciated and correct if posible
    {
        return shape;
    }

    constexpr bool is_square() const
    {
        return Shape::M == Shape::N;
    }

    constexpr size_t total_elements() const
    {
        return Shape::M * Shape::N;
    }

    T trace() const
    {
        static_assert(is_square(), "matrix is not square");

        T result = T();

        for (size_t i = 0; i < Shape::M; i++)
        {
            result += data()(i, i);
        }

        return result;
    }

    Matrix<T, N, M> traspose() const
    {
        Matrix<T, N, M> result();

        for (size_t i = 0; i < Shape::N; i++)
            for (size_t j = 0; j < Shape::M; j++)
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

    std::pair<bool, std::pair<size_t, size_t> > move_up_pivot(size_t row_index, size_t pivot)
    {
        const T zero_val = T();

        for (size_t i = row_index + 1; i < Shape::M; i++)
            if ((*this)(i, pivot) != zero_val)
            {
                swap_row(row_index, i);
                return std::pair(true, std::pair(row_index, i));
            }
        return std::pair(false, std::pair(0, 0));
    }

public:
    Matrix row_echelon() const
    {
        const T zero_val = T();
        Matrix result((*this));

        for (size_t i = 0, pivot = 0; i < Shape::M && pivot < Shape::N; i++, pivot++)
        {
            if (result(i, pivot) == zero_val)
                result.move_up_pivot(i, pivot);
            if (result(i, pivot) == zero_val)
            {
                i--;
                continue;
            }

            if (result(i, pivot) != 1)
            {
                result.change_row(i, result.row(i) * (1.f/result(i, pivot))); // Divide row by its first not null member
                result(i, pivot) = 1; // TODO a better way? to ensure pivot is 1
            }

            for (size_t j = 0; j < Shape::M; j++) // Substract lines by pivot line * first not null elm of current line
            {
                if (j == i)
                    continue;
                result.change_row(j, result.row(j) - result(j, pivot) * result.row(i));
                result(j, pivot) = 0; // TODO a better way? to ensure values above or below pivot are 0
            }
        }

        return result;
    }

    T determinant() const
    {
        static_assert(is_square(), "matrix is not square");

        const T zero_val = T();
        T result = 1;
        Matrix row_echelon_form((*this));

        for (size_t i = 0, pivot = 0; i < Shape::M && pivot < Shape::N; i++, pivot++)
        {
            if (row_echelon_form(i, pivot) == zero_val)
                if (row_echelon_form.move_up_pivot(i, pivot).first)
                    result *= -1; // Change sign if rows are changed; matrices properties duh

            if (row_echelon_form(i, pivot) == zero_val)
            {
                i--;
                continue;
            }

            for (size_t j = i + 1; j < Shape::M; j++) // Substract lines by pivot line * first not null elm of current line
            {
                row_echelon_form.change_row(j, row_echelon_form.row(j) - (row_echelon_form(j, pivot) / row_echelon_form(i, pivot)) * row_echelon_form.row(i));
                row_echelon_form(j, pivot) = 0; // TODO a better way? to ensure values above or below pivot are 0
            }
        }

        for (size_t i = 0; i < Shape::M; i++)
        {
            result *= row_echelon_form(i, i);
        }

        return result;
    }

    static Matrix identity() // TODO Can i build it in compile time, make it constexpr
    {
        Matrix matrix();

        for (size_t i = 0; i < Shape::M; i++)
        {
            matrix(i, i) = 1;
        }

        return matrix;
    }

    Matrix inverse() const
    {
        static_assert(is_square(), "matrix is not square");

        const T zero_val = T();
        Matrix tmp((*this));
        const Matrix identity = Matrix::identity(Shape::M);
        Matrix inverse(identity);

        for (size_t i = 0, pivot = 0; i < Shape::M && pivot < Shape::N; i++, pivot++)
        {
            if (tmp(i, pivot) == zero_val)
            {
                auto swap_res = tmp.move_up_pivot(i, pivot);
                if (swap_res.first)
                    inverse.swap_row(swap_res.second.first, swap_res.second.second);
            }

            if (tmp(i, pivot) == zero_val)
            {
                i--;
                continue;
            }

            if (tmp(i, pivot) != 1)
            {
                T val = 1.f/tmp(i, pivot);
                tmp.change_row(i, tmp.row(i) * val); // Divide row by its first not null member
                inverse.change_row(i, inverse.row(i) * val);
                tmp(i, pivot) = 1; // TODO a better way? to ensure pivot is 1
            }

            for (size_t j = 0; j < Shape::M; j++) // Substract lines by pivot line * first not null elm of current line
            {
                if (j == i)
                    continue;
                T val = tmp(j, pivot);
                tmp.change_row(j, tmp.row(j) - val * tmp.row(i));
                inverse.change_row(j, inverse.row(j) - val * inverse.row(i));
                tmp(j, pivot) = 0; // TODO a better way? to ensure values above or below pivot are 0
            }
        }

        if (tmp != identity)
            throw std::runtime_error(
                "inverse: matrix is singular"
            );

        return inverse;
    }

/***
 * Arithmetic operations
 */

    Matrix operator+(const Matrix& other) const
    {
        Matrix matrix();

        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                matrix(i, j) = (*this)(i, j) + other(i, j);
            }

        return matrix;
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                (*this)(i, j) += other(i, j);
            }

        return *this;
    }

    Matrix operator-(const Matrix& other) const
    {
        Matrix matrix();

        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                matrix(i, j) = (*this)(i, j) - other(i, j);
            }

        return matrix;
    }

    Matrix& operator-=(const Matrix& other)
    {
        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                (*this)(i, j) -= other(i, j);
            }

        return *this;
    }

    Matrix operator*(const T& scalar) const
    {
        Matrix matrix();

        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                matrix(i, j) = (*this)(i, j) * scalar;
            }

        return matrix;
    }

    Matrix& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < Shape::N; j++)
            {
                (*this)(i, j) *= scalar;
            }

        return *this;
    }

    Vector<T, M> operator*(const Vector<T, N>& u) const
    {
        static_assert(Shape::N != u.size(), "invalid multiplication, vector size(N) must be equal to matrix ncols(M)");

        Vector<T, M> result();

        for (size_t i = 0; i < Shape::M; i++)
        {
            result[i] = u.dot(row(i));
        }

        return result;
    }

    template<size_t O, size_t P>
    Matrix<T, M, P> operator*(const Matrix<T, O, P>& other) const // TODO
    {
        static_assert(Shape::N != other.shape().M, "invalid multiplication, first matrix ncols(M) must be equal to second matrix nrows(N)");

        Matrix<T, M, P> result();

        for (size_t i = 0; i < Shape::M; i++)
            for (size_t j = 0; j < other.shape().N; j++)
            {
                result(i, j) = row(i).dot(other.col(j));
            }

        return result;
    }

    template<size_t O>
    friend Vector<T, O>;

    template<typename t, size_t m, size_t n>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<t, m, n>& matrix);
};

template<typename T, size_t N>
class Matrix<T, 1, N>
{

public:

    Matrix(const Vector<T, N>& vector)
    {
        for (size_t i = 0; Shape::N; i++)
        {
            data()[i] = vector[i];
        }
    }

    Matrix& operator=(const Vector<T, N>& vector)
    {
        for (size_t i = 0; Shape::N; i++)
        {
            data()[i] = vector[i];
        }

        return *this;
    }
};

template<typename T, size_t M, size_t N>
inline std::ostream& operator<<(std::ostream& os, const typename Matrix<T, M, N>::Shape& shape)
{
    os << " (" << shape.m << "x" << shape.n << ")";
}

template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& os, const Matrix<T, M, N>& matrix)
{
    os << "{ ";

    for (size_t i = 0; i < matrix.shape().m; i++)
    {
        os << "( ";

        for (size_t j = 0; j < matrix.shape().n; j++)
        {
            os << matrix(i, j) << " ";
        }

        os << ") ";
    }
    
    os << "}";

    os << matrix.shape;
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
    Matrix<T, M, N> result();
    const Vector<float, 2> coefs({1 - scalar, scalar});

    for (size_t i = 0; i < result.shape().m; i++)
    {
        result.change_row(i, linear_combination<float>(Vector<Vector<T, N>, 2>{a.row(i), b.row(i)}, coefs));
    }

    return result;
}

}