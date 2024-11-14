#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(CosAngle, degree_00)
{
    matrix::Vector<float, 2> vector1 = {1.f, 0.f};
    matrix::Vector<float, 2> vector2 = {1.f, 0.f};

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_FLOAT_EQ(result, 1.f);
}

TEST(CosAngle, degree_90)
{
    matrix::Vector<float, 2> vector1 = {1.f, 0.f};
    matrix::Vector<float, 2> vector2 = {0.f, 1.f};

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_FLOAT_EQ(result, 0.f);
}

TEST(CosAngle, degree_180)
{
    matrix::Vector<float, 2> vector1 = {1.f, 0.f};
    matrix::Vector<float, 2> vector2 = {-1.f, 0.f};

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_FLOAT_EQ(result, -1.f);
}

TEST(CosAngle, degree_270)
{
    matrix::Vector<float, 2> vector1 = {1.f, 0.f};
    matrix::Vector<float, 2> vector2 = {0.f, -1.f};

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_FLOAT_EQ(result, 0.f);
}

TEST(CosAngle, Simple)
{
    matrix::Vector<float, 3> vector1 = {1.f, 2.f, 3.f};
    matrix::Vector<float, 3> vector2 = {4.f, 5.f, 6.f};

    float result = matrix::angle_cos(vector1, vector2);

    EXPECT_FLOAT_EQ(result,  0.974631846);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}