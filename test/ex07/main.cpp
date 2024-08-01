#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

/**
 * Vector
 */

TEST(VectorLinearMap, Identity)
{
    matrix::Matrix<TYPE> matrix({{1, 0}, {0, 1}});
    matrix::Vector<TYPE> vector({2, -3});

    matrix::Vector<TYPE> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<TYPE>({{1, 0}, {0, 1}}));
    EXPECT_EQ(vector, matrix::Vector<TYPE>({2, -3}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({2, -3}));
}

TEST(VectorLinearMap, MakeItDouble)
{
    matrix::Matrix<TYPE> matrix({{2, 0}, {0, 2}});
    matrix::Vector<TYPE> vector({2, 4});

    matrix::Vector<TYPE> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<TYPE>({{2, 0}, {0, 2}}));
    EXPECT_EQ(vector, matrix::Vector<TYPE>({2, 4}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({4, 8}));
}

TEST(VectorLinearMap, Simple)
{
    matrix::Matrix<TYPE> matrix({{1, 0, 4}, {2, 1, 3}});
    matrix::Vector<TYPE> vector({2, -3, 7});

    matrix::Vector<TYPE> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<TYPE>({{1, 0, 4}, {2, 1, 3}}));
    EXPECT_EQ(vector, matrix::Vector<TYPE>({2, -3, 7}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({30, 22}));
}

/**
 * Matrix
 */



/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}