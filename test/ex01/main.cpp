#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h" 
#include "../test_utils.hpp"

TEST(LinearCombination, Simple)
{
    matrix::Vector<int, 3> values = {1, 3, 5};
    matrix::Vector<int, 3> coefs = {1, 2, 1};

    int result = matrix::linear_combination(values, coefs);

    int expected = 12;
    EXPECT_EQ(result, expected);
}

TEST(LinearCombination, SimpleNonArith)
{
    matrix::Vector<A, 2> values = {A(3), A(2)};
    matrix::Vector<int, 2> coefs = {4, 5};

    A result = matrix::linear_combination(values, coefs);
    EXPECT_EQ(result, A(22));
}

TEST(LinearCombination, VectorSimple)
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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
