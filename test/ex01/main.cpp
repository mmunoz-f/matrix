#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 
#define VECTOR matrix::Vector<TYPE>

TEST(LinearCombination, Simple)
{
    std::vector<VECTOR> vectors{ {1, 2, 4}, {3, 5, 7} };
    std::vector<TYPE> coefs{2, 4};

    VECTOR vector = matrix::linear_combination<TYPE>(vectors, coefs);

    EXPECT_EQ(vector, VECTOR({14, 24, 36}));
}

TEST(LinearCombination, BadNCoefs)
{
    std::vector<VECTOR> vectors{ {1, 2, 4}, {3, 5, 7} };
    std::vector<TYPE> coefs{2, 4, 6};

    EXPECT_THROW({
        VECTOR vector = matrix::linear_combination<TYPE>(vectors, coefs);
    }, std::runtime_error);
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}