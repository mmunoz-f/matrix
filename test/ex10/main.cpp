#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"
#include "../test_utils.hpp"

TEST(MatrixRowEchelonForm, Identity)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 0.f,
	                                      0.f, 1.f};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 2, 2> expect = {1.f, 0.f,
	                                      0.f, 1.f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Simple)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 2.f,
	                                      3.f, 4.f};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 2, 2> expect = {1.f, 0.f,
                                          0.f, 1.f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Simple1)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 2.f,
	                                      2.f, 4.f};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();


    matrix::Matrix<float, 2, 2> expect = {1.f, 2.f,
                                          0.f, 0.f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, ZeroMidRow)
{
    matrix::Matrix<float, 4, 2> matrix = {8.f, 5.f,
	                                      0.f, 0.f,
                                          3.f, 5.f,
                                          7.f, 1.f};

    matrix::Matrix<float, 4, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 4, 2> expect = {1.f, 0.f,
                                          0.f, 1.f,
                                          0.f, 0.f,
                                          0.f, 0.f};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Complex)
{
    matrix::Matrix<float, 3, 5> matrix = {8.f, 5.f, -2.f, 4.f, 28.f,
                                          4.f, 2.5f, 20.f, 4.f, -4.f,
                                          8.f, 5.f, 1.f, 4.f, 17.f};

    matrix::Matrix<float, 3, 5> result = matrix.row_echelon();

    matrix::Matrix<float, 3, 5> expect = {1.f, 0.625f, 0.f, 0.f, -12.1666667f,
                                          0.f, 0.f, 1.f, 0.f, -3.6666667f,
                                          0.f, 0.f, 0.f, 1.f, 29.5f};
    expect_matrix_float_eq(result, expect);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
