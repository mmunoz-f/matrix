#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(Norm1, Simple)
{
    matrix::Vector<int, 3> vector = {1, -2, 3};

    int result = vector.norm_1();

    EXPECT_EQ(result, 2);
}

TEST(Norm, Simple)
{
    matrix::Vector<int, 3> vector = {1, -2, 3};

    float result = vector.norm();

    EXPECT_FLOAT_EQ(result, std::sqrt(14));
}

TEST(NormInf, Simple)
{
    matrix::Vector<int, 3> vector = {3, -5, 4};

    int result = vector.norm_inf();

    EXPECT_EQ(result, 5);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}