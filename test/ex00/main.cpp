#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

#define VECTOR matrix::Vector<TYPE>
#define MATRIX matrix::Matrix<TYPE>


/***
 * Vectors
 */

/** Equality */

TEST(VectorEquality, Simple)
{
    VECTOR vector1{1, 2, 3};
    VECTOR vector2{1, 2, 3};

    ASSERT_EQ(true, vector1 == vector2);

    EXPECT_EQ(vector1, VECTOR({1, 2, 3}));
    EXPECT_EQ(vector2, VECTOR({1, 2, 3}));
}

/** Addition */

TEST(VectorAddition, Simple) {
    VECTOR vector1{1, 2, 3};
    VECTOR vector2{0, 5, 3};

    VECTOR vector3 = vector1 + vector2;

    EXPECT_EQ(vector1, VECTOR({1, 2, 3}));
    EXPECT_EQ(vector2, VECTOR({0, 5, 3}));

    EXPECT_EQ(vector3, VECTOR({1, 7, 6}));
}

TEST(VectorAddition, AssignSimple)
{
    VECTOR vector1{6, 2, 3};
    VECTOR vector2{8, 1, 3};

    vector1 += vector2;

    EXPECT_EQ(vector2, VECTOR({8, 1, 3}));

    EXPECT_EQ(vector1, VECTOR({14, 3, 6}));
}

/** Substraction */

TEST(VectorSubstraction, Simple) {
    VECTOR vector1{1, 2, 3};
    VECTOR vector2{0, 5, 3};

    VECTOR vector3 = vector1 - vector2;

    EXPECT_EQ(vector1, VECTOR({1, 2, 3}));
    EXPECT_EQ(vector2, VECTOR({0, 5, 3}));

    EXPECT_EQ(vector3, VECTOR({1, -3, 0}));
}

TEST(VectorSubstraction, AssignSimple)
{
    VECTOR vector1{6, 2, 3};
    VECTOR vector2{8, 1, 3};

    vector1 -= vector2;

    EXPECT_EQ(vector2, VECTOR({8, 1, 3}));

    EXPECT_EQ(vector1, VECTOR({-2, 1, 0}));
}

/** Scalar Multiplication */

TEST(VectorScalarMultiplication, Simple)
{
    VECTOR vector1{1, 2, 3};
    TYPE scalar = 2;

    VECTOR vector2 = vector1 * scalar;

    EXPECT_EQ(scalar, 2);

    EXPECT_EQ(vector2, VECTOR({2, 4, 6}));
}

TEST(VectorScalarMultiplication, Reverse)
{
    VECTOR vector1{4, 2, -2};
    TYPE scalar = 5;

    VECTOR vector2 = scalar * vector1;

    EXPECT_EQ(scalar, 5);

    EXPECT_EQ(vector2, VECTOR({20, 10, -10}));
}

TEST(VectorScalarMultiplication, AssignSimple)
{
    VECTOR vector1{4, 6, 10};
    TYPE scalar = 3;

    vector1 *= scalar;

    EXPECT_EQ(scalar, 3);

    EXPECT_EQ(vector1, VECTOR({12, 18, 30}));
}


/***
 * Matrix
 */

/** Equality */

TEST(matrixEquality, Simple)
{
    MATRIX matrix1{{1, 2},{3, 4}};
    MATRIX matrix2{{1, 2},{3, 4}};

    ASSERT_EQ(true, matrix1 == matrix2);

    MATRIX expected{{1, 2},{3, 4}};
    EXPECT_EQ(matrix1, expected);
    expected = {{1, 2},{3, 4}};
    EXPECT_EQ(matrix2, expected);
}

/** Addition */

TEST(MatrixAddition, Simple)
{
    MATRIX matrix1{{1, 2},{1, 0}};
    MATRIX matrix2{{0, 5},{3, 4}};

    MATRIX matrix3 = matrix1 + matrix2;

    MATRIX expected{{1, 2},{1, 0}};
    EXPECT_EQ(matrix1, expected);
    expected = {{0, 5},{3, 4}};
    EXPECT_EQ(matrix2, expected);

    expected = {{1, 7},{4, 4}};
    EXPECT_EQ(matrix3, expected);
}

TEST(MatrixAddition, AssignSimple)
{
    MATRIX matrix1{{6, 2},{-2, 0}};
    MATRIX matrix2{{-3, 5},{1, -3}};

    matrix1 += matrix2;

    MATRIX expected{{-3, 5},{1, -3}};
    EXPECT_EQ(matrix2, expected);

    expected = {{3, 7},{-1, -3}};
    EXPECT_EQ(matrix1, expected);
}

/** Substraction */

TEST(MatrixSubstraction, Simple)
{
    MATRIX matrix1{{1, 2},{1, 0}};
    MATRIX matrix2{{-6, 2},{3, 4}};

    MATRIX matrix3 = matrix1 - matrix2;

    MATRIX expected{{1, 2},{1, 0}};
    EXPECT_EQ(matrix1, expected);
    expected = {{-6, 2},{3, 4}};
    EXPECT_EQ(matrix2, expected);

    expected = {{7, 0},{-2, -4}};
    EXPECT_EQ(matrix3, expected);
}

TEST(MatrixSubstraction, AssignSimple)
{
    MATRIX matrix1{{1, 2},{1, 0}};
    MATRIX matrix2{{-6, 2},{3, 4}};

    matrix1 -= matrix2;

    MATRIX expected{{-6, 2},{3, 4}};
    EXPECT_EQ(matrix2, expected);

    expected = {{7, 0},{-2, -4}};
    EXPECT_EQ(matrix1, expected);
}

/** Scalar Multiplication */

TEST(MatrixScalarMultiplication, Simple)
{
    MATRIX matrix1{{1, 2},{3, 4}};
    TYPE scalar = 2;

    MATRIX matrix2 = matrix1 * scalar;

    EXPECT_EQ(scalar, 2);

    MATRIX expected{{2, 4},{6, 8}};
    EXPECT_EQ(matrix2, expected);
}

TEST(MatrixScalarMultiplication, Reverse)
{
    MATRIX matrix1{{4, 2},{-2, 1}};
    TYPE scalar = 5;

    MATRIX matrix2 = scalar * matrix1;

    EXPECT_EQ(scalar, 5);

    MATRIX expected{{20, 10},{-10, 5}};
    EXPECT_EQ(matrix2, expected);
}

TEST(MatrixScalarMultiplication, AssignSimple)
{
    MATRIX matrix1{{4, 6},{2, -3}};
    TYPE scalar = 3;

    matrix1 *= scalar;

    EXPECT_EQ(scalar, 3);

    MATRIX expected{{12, 18},{6, -9}};
    EXPECT_EQ(matrix1, expected);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}