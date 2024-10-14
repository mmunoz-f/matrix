#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

#define int int 

/**
 * Vector
 */

TEST(VectorLinearMap, Identity)
{
    matrix::Matrix<int> matrix{{1, 0}, {0, 1}};
    matrix::Vector<int> vector{2, -3};

    matrix::Vector<int> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<int>({{1, 0}, {0, 1}}));
    EXPECT_EQ(vector, matrix::Vector<int>({2, -3}));

    EXPECT_EQ(result, matrix::Vector<int>({2, -3}));
}

TEST(VectorLinearMap, MakeItDouble)
{
    matrix::Matrix<int> matrix{{2, 0}, {0, 2}};
    matrix::Vector<int> vector{2, 4};

    matrix::Vector<int> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<int>({{2, 0}, {0, 2}}));
    EXPECT_EQ(vector, matrix::Vector<int>({2, 4}));

    EXPECT_EQ(result, matrix::Vector<int>({4, 8}));
}

TEST(VectorLinearMap, Simple)
{
    matrix::Matrix<int> matrix{{1, 0, 4}, {2, 1, 3}};
    matrix::Vector<int> vector{2, -3, 7};

    matrix::Vector<int> result = matrix * vector;

    EXPECT_EQ(matrix, matrix::Matrix<int>({{1, 0, 4}, {2, 1, 3}}));
    EXPECT_EQ(vector, matrix::Vector<int>({2, -3, 7}));

    EXPECT_EQ(result, matrix::Vector<int>({30, 22}));
}

// /**
//  * Matrix
//  */

// TEST(MatrixLinearMap, Identity0)
// {
//     matrix::Matrix<int> matrix1{{1, 0}, {0, 1}};
//     matrix::Matrix<int> matrix2{{1, 0}, {0, 1}};

//     matrix::Matrix<int> result = matrix1 * matrix2;

//     EXPECT_EQ(matrix1, matrix::Matrix<int>({{1, 0}, {0, 1}}));
//     EXPECT_EQ(matrix2, matrix::Matrix<int>({{1, 0}, {0, 1}}));

//     EXPECT_EQ(result, matrix::Matrix<int>({{1, 0}, {0, 1}}));
// }

// TEST(MatrixLinearMap, Identity)
// {
//     matrix::Matrix<int> matrix1{{1, 0}, {0, 1}};
//     matrix::Matrix<int> matrix2{{2, 1}, {4, 2}};

//     matrix::Matrix<int> result = matrix1 * matrix2;

//     EXPECT_EQ(matrix1, matrix::Matrix<int>({{1, 0}, {0, 1}}));
//     EXPECT_EQ(matrix2, matrix::Matrix<int>({{2, 1}, {4, 2}}));

//     EXPECT_EQ(result, matrix::Matrix<int>({{2, 1}, {4, 2}}));
// }

// TEST(MatrixLinearMap, MakeItDouble)
// {
//     matrix::Matrix<int> matrix1{{2, 0}, {0, 2}};
//     matrix::Matrix<int> matrix2{{2, 1}, {4, 2}};

//     matrix::Matrix<int> result = matrix1 * matrix2;

//     EXPECT_EQ(matrix1, matrix::Matrix<int>({{2, 0}, {0, 2}}));
//     EXPECT_EQ(matrix2, matrix::Matrix<int>({{2, 1}, {4, 2}}));

//     EXPECT_EQ(result, matrix::Matrix<int>({{4, 2}, {8, 4}}));
// }

// TEST(MatrixLinearMap, DiffDim)
// {
//     matrix::Matrix<int> matrix1{{1, 2, 3}, {1, 2, 3}};
//     matrix::Matrix<int> matrix2{{1, 2}, {1, 2}, {1, 2}};

//     matrix::Matrix<int> result = matrix1 * matrix2;

//     EXPECT_EQ(matrix1, matrix::Matrix<int>({{1, 2, 3}, {1, 2, 3}}));
//     EXPECT_EQ(matrix2, matrix::Matrix<int>({{1, 2}, {1, 2}, {1, 2}}));

//     EXPECT_EQ(result, matrix::Matrix<int>({{6, 12}, {6, 12}}));
// }

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}