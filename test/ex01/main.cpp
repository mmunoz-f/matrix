#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

TEST(LinearCombination, Simple)
{
    std::vector<matrix::Vector<TYPE> > vectors = { {1, 2}, {3, 5} };
    std::vector<TYPE> coefs({2, 4});

    matrix::Vector<TYPE> vector = matrix::linear_combination<TYPE>(vectors, coefs);

    EXPECT_EQ(vector, matrix::Vector<TYPE>({14, 24}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}