#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int

#define MATRIX matrix::Matrix<TYPE>

TEST(MatrixTrace, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};

    TYPE result = matrix.trace();

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_EQ(result, 2);
}

TEST(MatrixTrace, Simple)
{
    MATRIX matrix{{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}};

    TYPE result = matrix.trace();

    EXPECT_EQ(matrix, MATRIX({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}}));

    EXPECT_EQ(result, 9);
}

TEST(MatrixTrace, NotSquare)
{
    MATRIX matrix{{1, 0, 1}, {0, 1, 1}};

    EXPECT_THROW({
        matrix.trace();
    }, std::runtime_error);

    EXPECT_EQ(matrix, MATRIX({{1, 0, 1}, {0, 1, 1}}));
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}