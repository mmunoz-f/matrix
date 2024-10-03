#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(CrossProduct, Unit)
{
    matrix::Vector<int, 3> vector1 = {0, 0, 1};
    matrix::Vector<int, 3> vector2 = {1, 0, 0};

    matrix::Vector<int, 3> result = matrix::cross_product(vector1, vector2);

    matrix::Vector<int, 3> expt = {0, 1, 0};
    EXPECT_EQ(result, expt);
}

TEST(CrossProduct, Simple)
{
    matrix::Vector<int, 3> vector1{1, 2, 3};
    matrix::Vector<int, 3> vector2{4, 5, 6};

    matrix::Vector<int, 3> result = matrix::cross_product(vector1, vector2);

    matrix::Vector<int, 3> expt = {-3, 6, -3};
    EXPECT_EQ(result, expt);
}

TEST(CrossProduct, Simple1)
{
    matrix::Vector<int, 3> vector1{4, 2, -3};
    matrix::Vector<int, 3> vector2{-2, -5, 16};

    matrix::Vector<int, 3> result = matrix::cross_product(vector1, vector2);
    
    matrix::Vector<int, 3> expt = {17, -58, -16};
    EXPECT_EQ(result, expt);
}

// TEST(CrossProduct, NotComp) // This does not compile
// {
//     matrix::Vector<int, 2> vector1{0, 1};
//     matrix::Vector<int, 2> vector2{1, 0};

//     matrix::Vector<int, 2> result = matrix::cross_product(vector1, vector2);
// }

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}