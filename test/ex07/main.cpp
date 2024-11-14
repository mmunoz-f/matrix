#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define int int 

/**
 * Vector
 */

TEST(VectorLinearMap, Identity)
{
    matrix::Matrix<int, 2, 2> matrix = {1, 0,
                                        0, 1};
    matrix::Vector<int, 2> vector = {2, -3};

    matrix::Vector<int, 2> result = matrix * vector;

    matrix::Vector<int, 2> expect = {2, -3};
    EXPECT_EQ(result, expect);
}

TEST(VectorLinearMap, MakeItDouble)
{
    matrix::Matrix<int, 2, 2> matrix = {2, 0,
                                        0, 2};
    matrix::Vector<int, 2> vector = {2, 4};

    matrix::Vector<int, 2> result = matrix * vector;

    matrix::Vector<int, 2> expect = {4, 8};
    EXPECT_EQ(result, expect);
}

TEST(VectorLinearMap, Simple)
{
    matrix::Matrix<int, 2, 3> matrix = {1, 0, 4,
                                        2, 1, 3};
    matrix::Vector<int, 3> vector = {2, -3, 7};

    matrix::Vector<int, 2> result = matrix * vector;

    matrix::Vector<int, 2> expect = {30, 22};
    EXPECT_EQ(result, expect);
}

// /**
//  * Matrix
//  */

TEST(MatrixLinearMap, Identity0)
{
    matrix::Matrix<int, 2, 2> matrix1 = {1, 0,
                                         0, 1};
    matrix::Matrix<int, 2, 2> matrix2 = {1, 0,
                                         0, 1};

    matrix::Matrix<int, 2, 2> result = matrix1 * matrix2;

    matrix::Matrix<int, 2, 2> expect = {1, 0,
                                        0, 1};
    EXPECT_EQ(result, expect);
}

TEST(MatrixLinearMap, Identity)
{
    matrix::Matrix<int, 2, 2> matrix1 = {1, 0,
                                         0, 1};
    matrix::Matrix<int, 2, 2> matrix2 = {2, 1,
                                         4, 2};

    matrix::Matrix<int, 2, 2> result = matrix1 * matrix2;

    matrix::Matrix<int, 2, 2> expect = {2, 1,
                                        4, 2};
    EXPECT_EQ(result, expect);
}

TEST(MatrixLinearMap, MakeItDouble)
{
    matrix::Matrix<int, 2, 2> matrix1 = {2, 0, 
                                         0, 2};
    matrix::Matrix<int, 2, 2> matrix2 = {2, 1, 
                                         4, 2};

    matrix::Matrix<int, 2, 2> result = matrix1 * matrix2;

    matrix::Matrix<int, 2, 2> expect = {4, 2,
                                        8, 4};
    EXPECT_EQ(result, expect);
}

TEST(MatrixLinearMap, DiffDim)
{
    matrix::Matrix<int, 2, 3> matrix1 = {1, 2, 3, 
                                         1, 2, 3};
    matrix::Matrix<int, 3, 2> matrix2 = {1, 2, 
                                         1, 2,
                                         1, 2};

    matrix::Matrix<int, 2, 2> result = matrix1 * matrix2;

    matrix::Matrix<int, 2, 2> expect = {6, 12,
                                        6, 12};
    EXPECT_EQ(result, expect);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}