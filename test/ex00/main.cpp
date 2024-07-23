#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

/***
 * Vectors
 */

/** Equality */

TEST(VectorEquality, Simple)
{
    matrix::Vector<TYPE> vector1({1, 2, 3});
    matrix::Vector<TYPE> vector2({1, 2, 3});

    ASSERT_EQ(true, vector1 == vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({1, 2, 3}));
}

/** Addition */

TEST(VectorAddition, Simple) {
    matrix::Vector<TYPE> vector1({1, 2, 3});
    matrix::Vector<TYPE> vector2({0, 5, 3});

    matrix::Vector<TYPE> vector3 = vector1 + vector2;

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({0, 5, 3}));

    EXPECT_EQ(vector3, matrix::Vector<TYPE>({1, 7, 6}));
}

TEST(VectorAddition, AssignSimple)
{
    matrix::Vector<TYPE> vector1({6, 2, 3});
    matrix::Vector<TYPE> vector2({8, 1, 3});

    vector1 += vector2;

    EXPECT_EQ(vector2, matrix::Vector<TYPE>({8, 1, 3}));

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({14, 3, 6}));
}

/** Substraction */

TEST(VectorSubstraction, Simple) {
    matrix::Vector<TYPE> vector1({1, 2, 3});
    matrix::Vector<TYPE> vector2({0, 5, 3});

    matrix::Vector<TYPE> vector3 = vector1 - vector2;

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({0, 5, 3}));

    EXPECT_EQ(vector3, matrix::Vector<TYPE>({1, -3, 0}));
}

TEST(VectorSubstraction, AssignSimple)
{
    matrix::Vector<TYPE> vector1({6, 2, 3});
    matrix::Vector<TYPE> vector2({8, 1, 3});

    vector1 -= vector2;

    EXPECT_EQ(vector2, matrix::Vector<TYPE>({8, 1, 3}));

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({-2, 1, 0}));
}

/** Scalar Multiplication */

TEST(VectorScalarMultiplication, Simple)
{
    matrix::Vector<TYPE> vector1({1, 2, 3});
    TYPE scalar = 2;

    matrix::Vector<TYPE> vector2 = vector1 * scalar;

    EXPECT_EQ(scalar, 2);

    EXPECT_EQ(vector2, matrix::Vector<TYPE>({2, 4, 6}));
}

TEST(VectorScalarMultiplication, Reverse)
{
    matrix::Vector<TYPE> vector1({4, 2, -2});
    TYPE scalar = 5;

    matrix::Vector<TYPE> vector2 = scalar * vector1;

    EXPECT_EQ(scalar, 5);

    EXPECT_EQ(vector2, matrix::Vector<TYPE>({20, 10, -10}));
}

TEST(VectorScalarMultiplication, AssignSimple)
{
    matrix::Vector<TYPE> vector1({4, 6, 10});
    TYPE scalar = 3;

    vector1 *= scalar;

    EXPECT_EQ(scalar, 3);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({12, 18, 30}));
}


/***
 * Matrix
 */

/** Equality */

TEST(matrixEquality, Simple)
{
    matrix::Matrix<TYPE> matrix1({{1, 2},{3, 4}});
    matrix::Matrix<TYPE> matrix2({{1, 2},{3, 4}});

    ASSERT_EQ(true, matrix1 == matrix2);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{1, 2},{3, 4}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{1, 2},{3, 4}}));
}

/** Addition */

TEST(MatrixAddition, Simple)
{
    matrix::Matrix<TYPE> matrix1({{1, 2},{1, 0}});
    matrix::Matrix<TYPE> matrix2({{0, 5},{3, 4}});

    matrix::Matrix<TYPE> matrix3 = matrix1 + matrix2;

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{1, 2},{1, 0}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{0, 5},{3, 4}}));

    EXPECT_EQ(matrix3, matrix::Matrix<TYPE>({{1, 7},{4, 4}}));
}

TEST(MatrixAddition, AssignSimple)
{
    matrix::Matrix<TYPE> matrix1({{6, 2},{-2, 0}});
    matrix::Matrix<TYPE> matrix2({{-3, 5},{1, -3}});

    matrix1 += matrix2;

    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{-3, 5},{1, -3}}));

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{3, 7},{-1, -3}}));
}

/** Substraction */

TEST(MatrixSubstraction, Simple)
{
    matrix::Matrix<TYPE> matrix1({{1, 2},{1, 0}});
    matrix::Matrix<TYPE> matrix2({{-6, 2},{3, 4}});

    matrix::Matrix<TYPE> matrix3 = matrix1 - matrix2;

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{1, 2},{1, 0}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{-6, 2},{3, 4}}));

    EXPECT_EQ(matrix3, matrix::Matrix<TYPE>({{7, 0},{-2, -4}}));
}

TEST(MatrixSubstraction, AssignSimple)
{
    matrix::Matrix<TYPE> matrix1({{1, 2},{1, 0}});
    matrix::Matrix<TYPE> matrix2({{-6, 2},{3, 4}});

    matrix1 -= matrix2;

    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{-6, 2},{3, 4}}));

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{7, 0},{-2, -4}}));
}

/** Scalar Multiplication */

TEST(MatrixScalarMultiplication, Simple)
{
    matrix::Matrix<TYPE> matrix1({{1, 2},{3, 4}});
    TYPE scalar = 2;

    matrix::Matrix<TYPE> matrix2 = matrix1 * scalar;

    EXPECT_EQ(scalar, 2);

    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{2, 4},{6, 8}}));
}

TEST(MatrixScalarMultiplication, Reverse)
{
    matrix::Matrix<TYPE> matrix1({{4, 2},{-2, 1}});
    TYPE scalar = 5;

    matrix::Matrix<TYPE> matrix2 = scalar * matrix1;

    EXPECT_EQ(scalar, 5);

    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{20, 10},{-10, 5}}));
}

TEST(MatrixScalarMultiplication, AssignSimple)
{
    matrix::Matrix<TYPE> matrix1({{4, 6},{2, -3}});
    TYPE scalar = 3;

    matrix1 *= scalar;

    EXPECT_EQ(scalar, 3);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{12, 18},{6, -9}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}