#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float

#define VECTOR matrix::Vector<TYPE>
#define MATRIX matrix::Matrix<TYPE>

/**
 * Scalars
 */

TEST(ScalarLinearInterpolation, FullFirst)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, 0.f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 2);
}

TEST(ScalarLinearInterpolation, FullSecond)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, 1.f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 4);
}

TEST(ScalarLinearInterpolation, Simple)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, 0.3f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 2.6f);
}

TEST(ScalarLinearInterpolation, SimpleOposite)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, 0.7f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 3.4f);
}

TEST(ScalarLinearInterpolation, MakeItDouble)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, 2.f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 6.f);
}

TEST(ScalarLinearInterpolation, MakeItLess)
{
    TYPE x = 2;
    TYPE y = 4;

    float result = matrix::lerp(x, y, -1.f);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 4);

    EXPECT_EQ(result, 0.f);
}

/**
 * Vectors
 */

TEST(VectorLinearInterpolation, FullFirst)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2, 3}));
}

TEST(VectorLinearInterpolation, FullSecond)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 1.f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({4, 7}));
}

TEST(VectorLinearInterpolation, Simple)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.3f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2.6f, 4.2f}));
}

TEST(VectorLinearInterpolation, SimpleOposite)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.7f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({3.4f, 5.8f}));
}

TEST(VectorLinearInterpolation, MakeItDouble)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 2.f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({6.f, 11.f}));
}

TEST(VectorLinearInterpolation, MakeItLess)
{
    VECTOR vector1{2, 3};
    VECTOR vector2{4, 7};

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, -1.f);

    EXPECT_EQ(vector1, VECTOR({2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({0.f, -1.f}));
}

/**
 * Matrix
 */

TEST(MatrixLinearInterpolation, FullFirst)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{2, 3}}));
}

TEST(MatrixLinearInterpolation, FullSecond)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 1.f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{4, 7}}));
}

TEST(MatrixLinearInterpolation, Simple)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.3f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{2.6f, 4.2f}}));
}

TEST(MatrixLinearInterpolation, SimpleOposite)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.7f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{3.4f, 5.8f}}));
}

TEST(MatrixLinearInterpolation, MakeItDouble)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 2.f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{6.f, 11.f}}));
}

TEST(MatrixLinearInterpolation, MakeItLess)
{
    MATRIX matrix1{{2, 3}};
    MATRIX matrix2{{4, 7}};

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, -1.f);

    EXPECT_EQ(matrix1, MATRIX({{2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{0.f, -1.f}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}