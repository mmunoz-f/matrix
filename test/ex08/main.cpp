#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h" 

TEST(MatrixTrace, Identity)
{
    matrix::Matrix<int, 2, 2> matrix = {1, 0,
                                        0, 1};

    int result = matrix.trace();
    EXPECT_EQ(result, 2);
}

TEST(MatrixTrace, Simple)
{
    matrix::Matrix<int, 3, 3> matrix = { 2, -5,  0,
                                         4,  3,  7,
                                        -2,  3,  4};

    int result = matrix.trace();
    EXPECT_EQ(result, 9);
}

// TEST(MatrixTrace, NotSquare) // Should not compile
// {
//     matrix::Matrix<int, 2, 3> matrix = {1, 0, 1,
//                                         0, 1, 1};

//     int result = matrix.trace();
// }

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}