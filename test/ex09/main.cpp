#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int

#define MATRIX matrix::Matrix<TYPE>

TEST(MatrixTraspose, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};

    MATRIX result = matrix.traspose();

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}}));
}

TEST(MatrixTraspose, Simple)
{
    MATRIX matrix{{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}};

    MATRIX result = matrix.traspose();

    EXPECT_EQ(matrix, MATRIX({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}}));

    EXPECT_EQ(result, MATRIX({{2, 4, -2}, {-5, 3, 3}, {0, 7, 4}}));
}

TEST(MatrixTraspose, NotSquare)
{
    MATRIX matrix{{1, 0, 1}, {0, 1, 1}};

    MATRIX result = matrix.traspose();

    EXPECT_EQ(matrix, MATRIX({{1, 0, 1}, {0, 1, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}, {1, 1}}));
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}