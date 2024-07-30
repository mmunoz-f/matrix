#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float

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
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2, 3}));
}

TEST(VectorLinearInterpolation, FullSecond)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 1.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({4, 7}));
}

TEST(VectorLinearInterpolation, Simple)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.3f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2.6f, 4.2f}));
}

TEST(VectorLinearInterpolation, SimpleOposite)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.7f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({3.4f, 5.8f}));
}

TEST(VectorLinearInterpolation, MakeItDouble)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 2.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({6.f, 11.f}));
}

TEST(VectorLinearInterpolation, MakeItLess)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, -1.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({0.f, -1.f}));
}

/**
 * Matrix
 */

TEST(MatrixLinearInterpolation, FullFirst)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{2, 3}}));
}

TEST(MatrixLinearInterpolation, FullSecond)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 1.f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{4, 7}}));
}

TEST(MatrixLinearInterpolation, Simple)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.3f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{2.6f, 4.2f}}));
}

TEST(MatrixLinearInterpolation, SimpleOposite)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 0.7f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{3.4f, 5.8f}}));
}

TEST(MatrixLinearInterpolation, MakeItDouble)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, 2.f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{6.f, 11.f}}));
}

TEST(MatrixLinearInterpolation, MakeItLess)
{
    matrix::Matrix<TYPE> matrix1({{2, 3}});
    matrix::Matrix<TYPE> matrix2({{4, 7}});

    matrix::Matrix<float> matrix = matrix::lerp(matrix1, matrix2, -1.f);

    EXPECT_EQ(matrix1, matrix::Matrix<TYPE>({{2, 3}}));
    EXPECT_EQ(matrix2, matrix::Matrix<TYPE>({{4, 7}}));

    EXPECT_EQ(matrix, matrix::Matrix<float>({{0.f, -1.f}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}