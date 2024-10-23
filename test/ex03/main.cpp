#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"
#include "../helpers/A.hpp"

TEST(DotProduct, Simple)
{
    matrix::Vector<int, 3> vector1 = { 1,  2,  3};
    matrix::Vector<int, 3> vector2 = { 2, -3,  6};

    int result = vector1.dot(vector2);
    EXPECT_EQ(result, 14);
}

TEST(DotProduct, NonArith)
{
    matrix::Vector<A, 2> vector1 = {A(1), A(2)};
    matrix::Vector<A, 2> vector2 = {A(4), A(3)};

    A result = vector1.dot(vector2);
    EXPECT_EQ(result, A(10));
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}