#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

/**
 * Scalars
 */

TEST(ScalarLinearInterpolation, FullFirst)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, 0.f);

    EXPECT_EQ(result, 2);
}

TEST(ScalarLinearInterpolation, FullSecond)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, 1.f);

    EXPECT_EQ(result, 4);
}

TEST(ScalarLinearInterpolation, Simple)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, 0.3f);

    EXPECT_EQ(result, 2.6f);
}

TEST(ScalarLinearInterpolation, SimpleOposite)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, 0.7f);

    EXPECT_EQ(result, 3.4f);
}

TEST(ScalarLinearInterpolation, MakeItDouble)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, 2.f);

    EXPECT_EQ(result, 6.f);
}

TEST(ScalarLinearInterpolation, MakeItLess)
{
    float x = 2;
    float y = 4;

    float result = matrix::lerp(x, y, -1.f);

    EXPECT_EQ(result, 0.f);
}

/**
 * Vectors
 */

TEST(VectorLinearInterpolation, FullFirst)
{
    matrix::Vector<int, 2> vector1 = {2, 3};
    matrix::Vector<int, 2> vector2 = {4, 7};

    matrix::Vector<int, 2> vector = matrix::lerp(vector1, vector2, 0.f);

    matrix::Vector<int, 2> expt = {2, 3};
    EXPECT_EQ(vector, expt);
}

TEST(VectorLinearInterpolation, FullSecond)
{
    matrix::Vector<int,2 > vector1 = {2, 3};
    matrix::Vector<int, 2> vector2 = {4, 7};

    matrix::Vector<int, 2> vector = matrix::lerp(vector1, vector2, 1.f);

    matrix::Vector<int, 2> expt = {4, 7};
    EXPECT_EQ(vector, expt);
}

TEST(VectorLinearInterpolation, Simple)
{
    matrix::Vector<float, 2> vector1 = {2.f, 3.f};
    matrix::Vector<float, 2> vector2 = {4.f, 7.f};

    matrix::Vector<float, 2> vector = matrix::lerp(vector1, vector2, 0.3f);

    matrix::Vector<float, 2> expt = {2.6f, 4.2f};
    EXPECT_EQ(vector, expt);
}

TEST(VectorLinearInterpolation, SimpleOposite)
{
    matrix::Vector<float, 2> vector1 = {2.f, 3.f};
    matrix::Vector<float, 2> vector2 = {4.f, 7.f};

    matrix::Vector<float, 2> vector = matrix::lerp(vector1, vector2, 0.7f);

    matrix::Vector<float, 2> expt = {3.4f, 5.8f};
    EXPECT_EQ(vector, expt);
}

TEST(VectorLinearInterpolation, MakeItDouble)
{
    matrix::Vector<float, 2> vector1 = {2.f, 3.f};
    matrix::Vector<float, 2> vector2 = {4.f, 7.f};

    matrix::Vector<float, 2> vector = matrix::lerp(vector1, vector2, 2.f);

    matrix::Vector<float, 2> expt = {6.f, 11.f};
    EXPECT_EQ(vector, expt);
}

TEST(VectorLinearInterpolation, MakeItLess)
{
    matrix::Vector<float, 2> vector1 = {2.f, 3.f};
    matrix::Vector<float, 2> vector2 = {4.f, 7.f};

    matrix::Vector<float, 2> vector = matrix::lerp(vector1, vector2, -1.f);

    matrix::Vector<float, 2> expt = {0.f, -1.f};
    EXPECT_EQ(vector, expt);
}

/**
 * Matrix
 */

TEST(MatrixLinearInterpolation, FullFirst)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, 0.f);

    matrix::Matrix<float, 2, 1> expect = {2.f, 3.f};
    EXPECT_EQ(matrix, expect);
}

TEST(MatrixLinearInterpolation, FullSecond)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, 1.f);

    matrix::Matrix<float, 2, 1> expect = {4.f, 7.f};
    EXPECT_EQ(matrix, expect);
}

TEST(MatrixLinearInterpolation, Simple)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, 0.3f);

    matrix::Matrix<float, 2, 1> expect = {2.6f, 4.2f};
    EXPECT_EQ(matrix, expect);
}

TEST(MatrixLinearInterpolation, SimpleOposite)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, 0.7f);

    matrix::Matrix<float, 2, 1> expect = {3.4f, 5.8f};
    EXPECT_EQ(matrix, expect);
}

TEST(MatrixLinearInterpolation, MakeItDouble)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, 2.f);

    matrix::Matrix<float, 2, 1> expect = {6.f, 11.f};
    EXPECT_EQ(matrix, expect);
}

TEST(MatrixLinearInterpolation, MakeItLess)
{
    matrix::Matrix<float, 2, 1> matrix1 = {2.f, 3.f};
    matrix::Matrix<float, 2, 1> matrix2 = {4.f, 7.f};

    matrix::Matrix<float, 2, 1> matrix = matrix::lerp(matrix1, matrix2, -1.f);

    matrix::Matrix<float, 2, 1> expect = {0.f, -1.f};
    EXPECT_EQ(matrix, expect);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}