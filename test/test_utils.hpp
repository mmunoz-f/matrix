#pragma once

#include <ostream>

template<size_t M, size_t N>
void expect_matrix_float_eq(const matrix::Matrix<float, M, N>& result, const matrix::Matrix<float, M, N>& expect)
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			EXPECT_FLOAT_EQ(result(i, j), expect(i, j));
		}
	}
}

struct A {

    int n;
    A() : n() {}
    A(int n) : n(n) {}

    A& operator+=(const A& other)
    {
        n += other.n;

        return *this;
    }

    A operator-() const
    {
        return A(-n);
    }

    A operator*(const A& other) const
    {
        return A(n * other.n);
    }

    bool operator==(const A& other) const
    {
        return n == other.n;
    }

};

std::ostream& operator<<(std::ostream& os, const A& a)
{
    return os << a.n;
}
