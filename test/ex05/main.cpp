#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE float 

TEST(CosAngle, degree_00)
{
    matrix::Vector<TYPE> vector1({1.f, 0.f});
    matrix::Vector<TYPE> vector2({1.f, 0.f});

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1.f, 0.f}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({1.f, 0.f}));

    EXPECT_FLOAT_EQ(result, 1.f);
}

TEST(CosAngle, degree_90)
{
    matrix::Vector<TYPE> vector1({1.f, 0.f});
    matrix::Vector<TYPE> vector2({0.f, 1.f});

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1.f, 0.f}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({0.f, 1.f}));

    EXPECT_FLOAT_EQ(result, 0.f);
}

TEST(CosAngle, degree_180)
{
    matrix::Vector<TYPE> vector1({1.f, 0.f});
    matrix::Vector<TYPE> vector2({-1.f, 0.f});

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1.f, 0.f}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({-1.f, 0.f}));

    EXPECT_FLOAT_EQ(result, -1.f);
}

TEST(CosAngle, degree_270)
{
    matrix::Vector<TYPE> vector1({1.f, 0.f});
    matrix::Vector<TYPE> vector2({0.f, -1.f});

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1.f, 0.f}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({0.f, -1.f}));

    EXPECT_FLOAT_EQ(result, 0.f);
}

TEST(CosAngle, Simple)
{
    matrix::Vector<TYPE> vector1({1.f, 2.f, 3.f});
    matrix::Vector<TYPE> vector2({4.f, 5.f, 6.f});

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1.f, 2.f, 3.f}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4.f, 5.f, 6.f}));

    EXPECT_FLOAT_EQ(result,  0.974631846);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}