#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float

#define MATRIX matrix::Matrix<TYPE>

TEST(MatrixRowEchelonForm, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};

    MATRIX result = matrix.row_echelon();

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}}));
}

TEST(MatrixRowEchelonForm, Simple)
{
    MATRIX matrix{{1, 2}, {3, 4}};

    MATRIX result = matrix.row_echelon();

    EXPECT_EQ(matrix, MATRIX({{1, 2}, {3, 4}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}}));
}

TEST(MatrixRowEchelonForm, Simple1)
{
    MATRIX matrix{{1, 2}, {2, 4}};

    MATRIX result = matrix.row_echelon();

    EXPECT_EQ(matrix, MATRIX({{1, 2}, {2, 4}}));

    EXPECT_EQ(result, MATRIX({{1, 2}, {0, 0}}));
}

TEST(MatrixRowEchelonForm, ZeroMidRow)
{
    MATRIX matrix{{8, 5}, {0, 0}, {3, 5,}, {7, 1}};

    MATRIX result = matrix.row_echelon();

    EXPECT_EQ(matrix, MATRIX({{8, 5}, {0, 0}, {3, 5}, {7, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}, {0, 0}, {0, 0}}));
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

TEST(MatrixRowEchelonForm, Complex)
{
    MATRIX matrix{{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}};

    MATRIX result = matrix.row_echelon();

    EXPECT_EQ(matrix, MATRIX({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}}));

    expect_matrix_float_eq(result, MATRIX({{1, 0.625, 0, 0, -12.1666667}, {0, 0, 1, 0, -3.6666667}, {0, 0, 0, 1, 29.5}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}