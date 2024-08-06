#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

#define VECTOR matrix::Vector<TYPE>

TEST(DotProduct, Simple)
{
    VECTOR vector1{1, 2, 3};
    VECTOR vector2{2, -3, 6};

    TYPE result = vector1.dot(vector2);

    EXPECT_EQ(vector1, VECTOR({1, 2, 3}));
    EXPECT_EQ(vector2, VECTOR({2, -3, 6}));

    EXPECT_EQ(result, 14);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}