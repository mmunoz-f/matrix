#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

TEST(CrossProduct, Unit)
{
    matrix::Vector<TYPE> vector1({0, 0, 1});
    matrix::Vector<TYPE> vector2({1, 0, 0});

    matrix::Vector<TYPE> result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({0, 0, 1}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({1, 0, 0}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({0, 1, 0}));
}

TEST(CrossProduct, Simple)
{
    matrix::Vector<TYPE> vector1({1, 2, 3});
    matrix::Vector<TYPE> vector2({4, 5, 6});

    matrix::Vector<TYPE> result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 5, 6}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({-3, 6, -3}));
}

TEST(CrossProduct, Simple1)
{
    matrix::Vector<TYPE> vector1({4, 2, -3});
    matrix::Vector<TYPE> vector2({-2, -5, 16});

    matrix::Vector<TYPE> result = matrix::cross_product(vector1, vector2);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({4, 2, -3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({-2, -5, 16}));

    EXPECT_EQ(result, matrix::Vector<TYPE>({17, -58, -16}));
}

TEST(CrossProduct, Not3Dim)
{
    matrix::Vector<TYPE> vector1({0, 1});
    matrix::Vector<TYPE> vector2({1, 0});

    EXPECT_THROW({
        matrix::Vector<TYPE> result = matrix::cross_product(vector1, vector2);
    }, std::runtime_error);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({0, 1}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({1, 0}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}