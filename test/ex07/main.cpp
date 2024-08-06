#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define TYPE int 

#define VECTOR matrix::Vector<TYPE>
#define MATRIX matrix::Matrix<TYPE>

/**
 * Vector
 */

TEST(VectorLinearMap, Identity)
{
    MATRIX matrix{{1, 0}, {0, 1}};
    VECTOR vector{2, -3};

    VECTOR result = matrix * vector;

    EXPECT_EQ(matrix, MATRIX({{1, 0}, {0, 1}}));
    EXPECT_EQ(vector, VECTOR({2, -3}));

    EXPECT_EQ(result, VECTOR({2, -3}));
}

TEST(VectorLinearMap, MakeItDouble)
{
    MATRIX matrix{{2, 0}, {0, 2}};
    VECTOR vector{2, 4};

    VECTOR result = matrix * vector;

    EXPECT_EQ(matrix, MATRIX({{2, 0}, {0, 2}}));
    EXPECT_EQ(vector, VECTOR({2, 4}));

    EXPECT_EQ(result, VECTOR({4, 8}));
}

TEST(VectorLinearMap, Simple)
{
    MATRIX matrix{{1, 0, 4}, {2, 1, 3}};
    VECTOR vector{2, -3, 7};

    VECTOR result = matrix * vector;

    EXPECT_EQ(matrix, MATRIX({{1, 0, 4}, {2, 1, 3}}));
    EXPECT_EQ(vector, VECTOR({2, -3, 7}));

    EXPECT_EQ(result, VECTOR({30, 22}));
}

/**
 * Matrix
 */

TEST(MatrixLinearMap, Identity0)
{
    MATRIX matrix1{{1, 0}, {0, 1}};
    MATRIX matrix2{{1, 0}, {0, 1}};

    MATRIX result = matrix1 * matrix2;

    EXPECT_EQ(matrix1, MATRIX({{1, 0}, {0, 1}}));
    EXPECT_EQ(matrix2, MATRIX({{1, 0}, {0, 1}}));

    EXPECT_EQ(result, MATRIX({{1, 0}, {0, 1}}));
}

TEST(MatrixLinearMap, Identity)
{
    MATRIX matrix1{{1, 0}, {0, 1}};
    MATRIX matrix2{{2, 1}, {4, 2}};

    MATRIX result = matrix1 * matrix2;

    EXPECT_EQ(matrix1, MATRIX({{1, 0}, {0, 1}}));
    EXPECT_EQ(matrix2, MATRIX({{2, 1}, {4, 2}}));

    EXPECT_EQ(result, MATRIX({{2, 1}, {4, 2}}));
}

TEST(MatrixLinearMap, MakeItDouble)
{
    MATRIX matrix1{{2, 0}, {0, 2}};
    MATRIX matrix2{{2, 1}, {4, 2}};

    MATRIX result = matrix1 * matrix2;

    EXPECT_EQ(matrix1, MATRIX({{2, 0}, {0, 2}}));
    EXPECT_EQ(matrix2, MATRIX({{2, 1}, {4, 2}}));

    EXPECT_EQ(result, MATRIX({{4, 2}, {8, 4}}));
}

TEST(MatrixLinearMap, DiffDim)
{
    MATRIX matrix1{{1, 2, 3}, {1, 2, 3}};
    MATRIX matrix2{{1, 2}, {1, 2}, {1, 2}};

    MATRIX result = matrix1 * matrix2;

    EXPECT_EQ(matrix1, MATRIX({{1, 2, 3}, {1, 2, 3}}));
    EXPECT_EQ(matrix2, MATRIX({{1, 2}, {1, 2}, {1, 2}}));

    EXPECT_EQ(result, MATRIX({{6, 12}, {6, 12}}));
}

/***************************** */

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}