#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"
#include "../test_utils.hpp"

TEST(MatrixRowEchelonForm, Identity)
{
    matrix::Matrix<float, 2, 2> matrix = {1, 0,
	                                  0, 1};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 2, 2> expect = {1, 0,
	                                  0, 1};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Simple)
{
    matrix::Matrix<float, 2, 2> matrix = {1, 2,
	                                  3, 4};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 2, 2> expect = {1, 0,
                                          0, 1};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Simple1)
{
    matrix::Matrix<float, 2, 2> matrix = {1, 2,
	                                  2, 4};

    matrix::Matrix<float, 2, 2> result = matrix.row_echelon();


    matrix::Matrix<float, 2, 2> expect = {1, 2,
                                          0, 0};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, ZeroMidRow)
{
    matrix::Matrix<float, 4, 2> matrix = {8, 5,
	                                  0, 0,
					  3, 5,
					  7, 1};

    matrix::Matrix<float, 4, 2> result = matrix.row_echelon();

    matrix::Matrix<float, 4, 2> expect = {1, 0,
                                          0, 1,
                                          0, 0,
                                          0, 0};
    EXPECT_EQ(result, expect);
}

TEST(MatrixRowEchelonForm, Complex)
{
    matrix::Matrix<float, 3, 5> matrix = {8, 5, -2, 4, 28,
	                                  4, 2.5, 20, 4, -4,
					  8, 5, 1, 4, 17};

    matrix::Matrix<float, 3, 5> result = matrix.row_echelon();

    matrix::Matrix<float, 3, 5> expect = {1, 0.625, 0, 0, -12.1666667,
	                                  0, 0, 1, 0, -3.6666667,
				          0, 0, 0, 1, 29.5};
    expect_matrix_float_eq(result, expect);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
