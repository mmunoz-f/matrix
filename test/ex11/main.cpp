#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(MatrixDeterminant, Identity)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 0.f,
                                          0.f, 1.f};

    float result = matrix.determinant();

    EXPECT_FLOAT_EQ(result, 1);
}

TEST(MatrixDeterminant, SimpleOnes)
{
    matrix::Matrix<float, 2, 2> matrix = { 1.f, -1.f,
                                          -1.f,  1.f};

    float result = matrix.determinant();

    EXPECT_FLOAT_EQ(result, 0);
}

TEST(MatrixDeterminant, Diagonal)
{
    matrix::Matrix<float, 3, 3> matrix = {2.f, 0.f, 0.f,
                                          0.f, 2.f, 0.f,
                                          0.f, 0.f, 2.f};
        
    float result = matrix.determinant();

    EXPECT_FLOAT_EQ(result, 8);
}

TEST(MatrixDeterminant, Simple)
{
    matrix::Matrix<float, 3, 3> matrix = {8.f, 5.f, -2.f,
                                          4.f, 7.f, 20.f,
                                          7.f, 6.f,  1.f};
        
    float result = matrix.determinant();

    EXPECT_FLOAT_EQ(result, -174);
}

TEST(MatrixDeterminant, Complex)
{
    matrix::Matrix<float, 4, 4> matrix = {8.f, 5.f, -2.f, 4.f,
                                          4.f, 2.5f, 20.f, 4.f,
                                          8.f, 5.f, 1.f, 4.f,
                                          28.f, -4.f, 17.f, 1.f};
        
    float result = matrix.determinant();

    EXPECT_FLOAT_EQ(result, 1032);
}

// TEST(MatrixDeterminant, NotSquare) // Does not compile
// {
//     matrix::Matrix<float, 2, 3> matrix = {1.f, 0.f, 1.f,
//                                           0.f, 1.f, 1.f};
//     matrix.determinant();
// }

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
