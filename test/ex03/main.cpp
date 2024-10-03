#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(DotProduct, Simple)
{
    matrix::Vector<int, 3> vector1 = {1, 2, 3};
    matrix::Vector<int, 3> vector2 = {2, -3, 6};

    int result = vector1.dot(vector2);

    EXPECT_EQ(result, 14);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}