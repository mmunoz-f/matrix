#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

TEST(Norm1, Simple)
{
    matrix::Vector<TYPE> vector({1, -2, 3});

    TYPE result = vector.norm_1();

    EXPECT_EQ(vector, matrix::Vector<TYPE>({1, -2, 3}));

    EXPECT_EQ(result, 2);
}

TEST(Norm, Simple)
{
    matrix::Vector<TYPE> vector({1, -2, 3});

    float result = vector.norm();

    EXPECT_EQ(vector, matrix::Vector<TYPE>({1, -2, 3}));

    EXPECT_FLOAT_EQ(result, std::sqrt(14));
}

TEST(NormInf, Simple)
{
    matrix::Vector<TYPE> vector({3, -5, 4});

    TYPE result = vector.norm_inf();

    EXPECT_EQ(vector, matrix::Vector<TYPE>({3, -5, 4}));

    EXPECT_EQ(result, 5);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}