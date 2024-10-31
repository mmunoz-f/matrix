#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"
#include "../test_utils.hpp"

TEST(MatrixInverse, Identity)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 0.f,
                                          0.f, 1.f};

    matrix::Matrix<float, 2, 2> result = matrix.inverse();

    matrix::Matrix<float, 2, 2> expect = {1.f, 0.f,
                                          0.f, 1.f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixInverse, Diagonal)
{
    matrix::Matrix<float, 3, 3> matrix = {2.f, 0.f, 0.f,
                                          0.f, 2.f, 0.f,
                                          0.f, 0.f, 2.f};

    matrix::Matrix<float, 3, 3> result = matrix.inverse();

    matrix::Matrix<float, 3, 3> expect = {0.5f, 0.f, 0.f, 
                                          0.f, 0.5f, 0.f,
                                          0.f, 0.f, 0.5f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixInverse, Simple)
{
    matrix::Matrix<float, 3, 3> matrix = {8.f, 5.f, -2.f,
                                          4.f, 7.f, 20.f,
                                          7.f, 6.f, 1.f};

    matrix::Matrix<float, 3, 3> result = matrix.inverse();

    matrix::Matrix<float, 3, 3> expect = { 0.649425287f,  0.097701149f, -0.655172414f,
                                          -0.781609195f, -0.126436782f,  0.965517241f,
                                           0.143678161f,  0.074712644f, -0.206896552f};
    expect_matrix_float_eq(result, expect);
}

TEST(MatrixInverse, Singular)
{
    matrix::Matrix<float, 2, 2> matrix = {3.f, 6.f,
                                          2.f, 4.f};

    EXPECT_THROW({
        matrix.inverse();
    }, std::runtime_error);
}

// TEST(MatrixInverse, NotSquare) // This wont compile
// {
//     matrix::Matrix<float, 2, 3> matrix = {1.f, 0.f, 1.f,
//                                           0.f, 1.f, 1.f};
//
//     matrix.inverse();
// }

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}