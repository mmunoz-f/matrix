#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

TEST(LinearInterpolation, FullFirst)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2, 3}));
}

TEST(LinearInterpolation, FullSecond)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 1.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({4, 7}));
}

TEST(LinearInterpolation, Simple)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.3f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({2.6f, 4.2f}));
}

TEST(LinearInterpolation, SimpleOposite)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 0.7f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({3.4f, 5.8f}));
}

TEST(LinearInterpolation, MakeItDouble)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, 2.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({6.f, 11.f}));
}

TEST(LinearInterpolation, MakeItLess)
{
    matrix::Vector<TYPE> vector1({2, 3});
    matrix::Vector<TYPE> vector2({4, 7});

    matrix::Vector<float> vector = matrix::lerp(vector1, vector2, -1.f);

    EXPECT_EQ(vector1, matrix::Vector<TYPE>({2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<TYPE>({4, 7}));

    EXPECT_EQ(vector, matrix::Vector<float>({0.f, -1.f}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}