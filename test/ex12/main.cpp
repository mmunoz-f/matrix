#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float

#define MATRIX matrix::Matrix<TYPE>

TEST(MatrixInverse, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};

    MATRIX result = matrix.inverse();

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}}));
}

TEST(MatrixInverse, Diagonal)
{
    MATRIX matrix{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};

    MATRIX result = matrix.inverse();

    EXPECT_EQ(matrix, MATRIX({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}}));

    EXPECT_EQ(result, MATRIX({{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}}));
}

void expect_matrix_float_eq(const MATRIX& result, const MATRIX& expected)
{
    if (result.shape() != expected.shape())
        FAIL();

    for (size_t i = 0; i < result.shape().first; i++)
        for (size_t j = 0; j < result.shape().second; j++)
        {
            EXPECT_FLOAT_EQ(result(i, j), expected(i, j));
        }
}

TEST(MatrixInverse, Simple)
{
    MATRIX matrix{{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};

    MATRIX result = matrix.inverse();

    EXPECT_EQ(matrix, MATRIX({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}}));

    expect_matrix_float_eq(result, MATRIX({{ 0.649425287,  0.097701149,  0.655172414},
                                           {-0.781609195, -0.126436782,  0.965517241},
                                           { 0.143678161,  0.074712644, -0.206896552}}));
}

TEST(MatrixInverse, Singular)
{
    MATRIX matrix{{3, 6}, {2, 4}};

    EXPECT_THROW({
        matrix.inverse();
    }, std::runtime_error);

    EXPECT_EQ(matrix, MATRIX({{3, 6}, {2, 4}}));
}

TEST(MatrixInverse, NotSquare)
{
    MATRIX matrix{{1, 0, 1}, {0, 1, 1}};

    EXPECT_THROW({
        matrix.inverse();
    }, std::runtime_error);

    EXPECT_EQ(matrix, MATRIX({{1, 0, 1}, {0, 1, 1}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}