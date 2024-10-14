#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

/***
 * Vectors
 */

/** Equality */

TEST(VectorEquality, Simple)
{
    matrix::Vector<int, 3> vector1 = {1, 2, 3};
    matrix::Vector<int, 3> vector2 = {1, 2, 3};

    ASSERT_EQ(true, vector1 == vector2);
}

/** Addition */

TEST(VectorAddition, Simple) {
    matrix::Vector<int, 3> vector1 = {1, 2, 3};
    matrix::Vector<int, 3> vector2 = {0, 5, 3};

    matrix::Vector<int, 3> vector3 = vector1 + vector2;

    matrix::Vector<int, 3> expt = {1, 7, 6};
    EXPECT_EQ(vector3, expt);
}

TEST(VectorAddition, AssignSimple)
{
    matrix::Vector<int, 3> vector1 = {6, 2, 3};
    matrix::Vector<int, 3> vector2 = {8, 1, 3};

    vector1 += vector2;

    matrix::Vector<int, 3> expt = {14, 3, 6};
    EXPECT_EQ(vector1, expt);
}

/** Substraction */

TEST(VectorSubstraction, Simple) {
    matrix::Vector<int, 3> vector1 = {1, 2, 3};
    matrix::Vector<int, 3> vector2 = {0, 5, 3};

    matrix::Vector<int, 3> vector3 = vector1 - vector2;

    matrix::Vector<int, 3> expt = {1, -3, 0};
    EXPECT_EQ(vector3, expt);
}

TEST(VectorSubstraction, AssignSimple)
{
    matrix::Vector<int, 3> vector1 = {6, 2, 3};
    matrix::Vector<int, 3> vector2 = {8, 1, 3};

    vector1 -= vector2;

    matrix::Vector<int, 3> expt = {-2, 1, 0};
    EXPECT_EQ(vector1, expt);
}

/** Scalar Multiplication */

TEST(VectorScalarMultiplication, Simple)
{
    matrix::Vector<int, 3> vector1 = {1, 2, 3};
    int scalar = 2;

    matrix::Vector<int, 3> vector2 = vector1 * scalar;

    matrix::Vector<int, 3> expt = {2, 4, 6};
    EXPECT_EQ(vector2, expt);
}

TEST(VectorScalarMultiplication, Reverse)
{
    matrix::Vector<int, 3> vector1 = {4, 2, -2};
    int scalar = 5;

    matrix::Vector<int, 3> vector2 = scalar * vector1;

    matrix::Vector<int, 3> expt = {20, 10, -10};
    EXPECT_EQ(vector2, expt);
}

TEST(VectorScalarMultiplication, AssignSimple)
{
    matrix::Vector<int, 3> vector1 = {4, 6, 10};
    int scalar = 3;

    vector1 *= scalar;

    EXPECT_EQ(scalar, 3);

    matrix::Vector<int, 3> expt = {12, 18, 30};
    EXPECT_EQ(vector1, expt);
}


/***
 * Matrix
 */

/** Equality */

TEST(matrixEquality, Simple)
{
    matrix::Matrix<int, 2, 2> matrix1 = {1, 2,
                                         3, 4};
    matrix::Matrix<int, 2, 2> matrix2 = {1, 2,
                                         3, 4};

    ASSERT_EQ(true, matrix1 == matrix2);
}

/** Addition */

TEST(MatrixAddition, Simple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 1,  2,
                                          1,  0};
    matrix::Matrix<int, 2, 2> matrix2 = { 0,  5,
                                          3,  4};

    matrix::Matrix<int, 2, 2> matrix3 = matrix1 + matrix2;

    matrix::Matrix<int, 2, 2> expected = { 1,  7,
                                           4,  4};
    EXPECT_EQ(matrix3, expected);
}

TEST(MatrixAddition, AssignSimple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 6,  2,
                                         -2,  0};
    matrix::Matrix<int, 2, 2> matrix2 = {-3,  5,
                                          1, -3};

    matrix1 += matrix2;

    matrix::Matrix<int, 2, 2> expected = { 3,  7,
                                          -1, -3};
    EXPECT_EQ(matrix1, expected);
}

/** Substraction */

TEST(MatrixSubstraction, Simple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 1,  2,
                                          1,  0};
    matrix::Matrix<int, 2, 2> matrix2 = {-6,  2,
                                          3,  4};

    matrix::Matrix<int, 2, 2> matrix3 = matrix1 - matrix2;

    matrix::Matrix<int, 2, 2> expected = { 7,  0,
                                          -2, -4};
    EXPECT_EQ(matrix3, expected);
}

TEST(MatrixSubstraction, AssignSimple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 1,  2,
                                          1,  0};
    matrix::Matrix<int, 2, 2> matrix2 = {-6,  2,
                                          3,  4};

    matrix1 -= matrix2;

    matrix::Matrix<int, 2, 2> expected = { 7,  0,
                                          -2, -4};
    EXPECT_EQ(matrix1, expected);
}

/** Scalar Multiplication */

TEST(MatrixScalarMultiplication, Simple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 1,  2,
                                          3,  4};
    int scalar = 2;

    matrix::Matrix<int, 2, 2> matrix2 = matrix1 * scalar;

    matrix::Matrix<int, 2, 2> expected = { 2,  4,
                                           6,  8};
    EXPECT_EQ(matrix2, expected);
}

TEST(MatrixScalarMultiplication, Reverse)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 4,  2,
                                         -2,  1};
    int scalar = 5;

    matrix::Matrix<int, 2, 2> matrix2 = scalar * matrix1;

    matrix::Matrix<int, 2, 2> expected = { 20,  10,
                                          -10,   5};
    EXPECT_EQ(matrix2, expected);
}

TEST(MatrixScalarMultiplication, AssignSimple)
{
    matrix::Matrix<int, 2, 2> matrix1 = { 4,  6,
                                          2, -3};
    int scalar = 3;

    matrix1 *= scalar;

    matrix::Matrix<int, 2, 2> expected = { 12,  18,
                                            6,  -9};
    EXPECT_EQ(matrix1, expected);
}

/***************************** */

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}