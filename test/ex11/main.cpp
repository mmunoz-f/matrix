#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float

#define MATRIX matrix::Matrix<TYPE>

TEST(MatrixDeterminant, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};

    TYPE result = matrix.determinant();

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_FLOAT_EQ(result, 1);
}

TEST(MatrixDeterminant, SimpleOnes)
{
    MATRIX matrix{{1, -1}, {-1, 1}};

    TYPE result = matrix.determinant();

    EXPECT_EQ(matrix, MATRIX({{1, -1}, {-1, 1}}));

    EXPECT_FLOAT_EQ(result, 0);
}

TEST(MatrixDeterminant, Diagonal)
{
    MATRIX matrix{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
        
    TYPE result = matrix.determinant();

    EXPECT_EQ(matrix, MATRIX({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}}));

    EXPECT_FLOAT_EQ(result, 8);
}

TEST(MatrixDeterminant, Simple)
{
    MATRIX matrix{{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};
        
    TYPE result = matrix.determinant();

    EXPECT_EQ(matrix, MATRIX({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}}));

    EXPECT_FLOAT_EQ(result, -174);
}

TEST(MatrixDeterminant, Complex)
{
    MATRIX matrix{{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}};
        
    TYPE result = matrix.determinant();

    EXPECT_EQ(matrix, MATRIX({{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}}));

    EXPECT_FLOAT_EQ(result, 1032);
}

TEST(MatrixDeterminant, NotSquare)
{
    MATRIX matrix{{1, 0, 1}, {0, 1, 1}};

    EXPECT_THROW({
        matrix.determinant();
    }, std::runtime_error);

    EXPECT_EQ(matrix, MATRIX({{1, 0, 1}, {0, 1, 1}}));
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}