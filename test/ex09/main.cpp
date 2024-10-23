#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(MatrixTraspose, Identity)
{
    matrix::Matrix<int, 2, 2> matrix = {1, 0,
                                        0, 1};

    matrix::Matrix<int, 2, 2> result = matrix.traspose();

    matrix::Matrix<int, 2, 2> expect = {1, 0,
                                        0, 1};
    EXPECT_EQ(result, expect);
}

TEST(MatrixTraspose, Simple)
{
    matrix::Matrix<int, 3, 3> matrix = { 2, -5,  0,
                                         4,  3,  7,
                                        -2,  3,  4};

    matrix::Matrix<int, 3, 3> result = matrix.traspose();

    matrix::Matrix<int, 3, 3> expect = { 2,  4, -2,
                                        -5,  3,  3,
                                         0,  7,  4};
    EXPECT_EQ(result, expect);
}

TEST(MatrixTraspose, NotSquare)
{
    matrix::Matrix<int, 2, 3> matrix = {1, 0, 1,
                                        0, 1, 1};

    matrix::Matrix<int, 3, 2> result = matrix.traspose();

    matrix::Matrix<int, 3, 2> expect = {1, 0,
                                        0, 1,
                                        1, 1};
    EXPECT_EQ(result, expect);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}