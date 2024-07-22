#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

/***
 * Vectors
 */

/** Addition */

TEST(VectorAddition, Simple) {
    matrix::Vector<int> vector1({1, 2, 3});
    matrix::Vector<int> vector2({0, 5, 3});

    matrix::Vector<int> vector3 = vector1 + vector2;

    EXPECT_EQ(vector1, matrix::Vector<int>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<int>({0, 5, 3}));

    EXPECT_EQ(vector3, matrix::Vector<int>({1, 7, 6}));
}

/** Assign Additions */

TEST(VectorAssignAddition, Simple)
{
    matrix::Vector<int> vector1({6, 2, 3});
    matrix::Vector<int> vector2({8, 1, 3});

    vector1 += vector2;

    EXPECT_EQ(vector2, matrix::Vector<int>({8, 1, 3}));

    EXPECT_EQ(vector1, matrix::Vector<int>({14, 3, 6}));
}

/** Substraction */

TEST(VectorSubstraction, Simple) {
    matrix::Vector<int> vector1({1, 2, 3});
    matrix::Vector<int> vector2({0, 5, 3});

    matrix::Vector<int> vector3 = vector1 - vector2;

    EXPECT_EQ(vector1, matrix::Vector<int>({1, 2, 3}));
    EXPECT_EQ(vector2, matrix::Vector<int>({0, 5, 3}));

    EXPECT_EQ(vector3, matrix::Vector<int>({1, -3, 0}));
}

/** Assign Additions */

TEST(VectorAssignSubstraction, Simple)
{
    matrix::Vector<int> vector1({6, 2, 3});
    matrix::Vector<int> vector2({8, 1, 3});

    vector1 -= vector2;

    EXPECT_EQ(vector2, matrix::Vector<int>({8, 1, 3}));

    EXPECT_EQ(vector1, matrix::Vector<int>({-2, 1, 0}));
}

/** Scalar Multiplication */

TEST(VectorScalarMultiplication, Simple)
{
    matrix::Vector<int> vector1({1, 2, 3});
    int scalar = 2;

    matrix::Vector<int> vector2 = vector1 * scalar;

    EXPECT_EQ(scalar, 2);

    EXPECT_EQ(vector2, matrix::Vector<int>({2, 4, 6}));
}

TEST(VectorScalarMultiplication, Reverse)
{
    matrix::Vector<int> vector1({4, 2, -2});
    int scalar = 5;

    matrix::Vector<int> vector2 = scalar * vector1;

    EXPECT_EQ(scalar, 5);

    EXPECT_EQ(vector2, matrix::Vector<int>({20, 10, -10}));
}

/** Assign Scalar Multiplication */

TEST(VectorAssignScalarMultiplication, Simple)
{
    matrix::Vector<int> vector1({4, 6, 10});
    int scalar = 3;

    vector1 *= scalar;

    EXPECT_EQ(scalar, 3);

    EXPECT_EQ(vector1, matrix::Vector<int>({12, 18, 30}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}