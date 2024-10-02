#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h" 

TEST(LinearCombination, Simple)
{
    matrix::Vector<int, 3> vector1 = {1, 2, 4};
    matrix::Vector<int, 3> vector2 = {3, 5, 7};

    matrix::Vector<matrix::Vector<int, 3>, 2> vectors = { vector1, vector2 };
    matrix::Vector<int, 2> coefs = {2, 4};

    auto vector = matrix::linear_combination(vectors, coefs);

    matrix::Vector<int, 3> expt = {14, 24, 36};
    EXPECT_EQ(vector, expt);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}