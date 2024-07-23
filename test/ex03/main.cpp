#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

TEST(DotProduct, Simple)
{
    matrix::Vector<TYPE> vector1({1, 2, 3});
    matrix::Vector<TYPE> vector2({2, -3, 6});

    TYPE result = vector1.dot_product(vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({2, -3, 6}));

    EXPECT_EQ(result, 14);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}