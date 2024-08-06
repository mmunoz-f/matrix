#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

#define VECTOR matrix::Vector<TYPE>

TEST(CrossProduct, Unit)
{
    VECTOR vector1{0, 0, 1};
    VECTOR vector2{1, 0, 0};

    VECTOR result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, VECTOR({0, 0, 1}));
    EXPECT_EQ(vector2, VECTOR({1, 0, 0}));

    EXPECT_EQ(result, VECTOR({0, 1, 0}));
}

TEST(CrossProduct, Simple)
{
    VECTOR vector1{1, 2, 3};
    VECTOR vector2{4, 5, 6};

    VECTOR result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, VECTOR({1, 2, 3}));
    EXPECT_EQ(vector2, VECTOR({4, 5, 6}));

    EXPECT_EQ(result, VECTOR({-3, 6, -3}));
}

TEST(CrossProduct, Simple1)
{
    VECTOR vector1{4, 2, -3};
    VECTOR vector2{-2, -5, 16};

    VECTOR result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, VECTOR({4, 2, -3}));
    EXPECT_EQ(vector2, VECTOR({-2, -5, 16}));

    EXPECT_EQ(result, VECTOR({17, -58, -16}));
}

TEST(CrossProduct, Not3Dim)
{
    VECTOR vector1{0, 1};
    VECTOR vector2{1, 0};

    EXPECT_THROW({
        VECTOR result = matrix::cross_product(vector1, vector2);
    }, std::runtime_error);

    EXPECT_EQ(vector1, VECTOR({0, 1}));
    EXPECT_EQ(vector2, VECTOR({1, 0}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}