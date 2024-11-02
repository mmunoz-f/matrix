#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"

TEST(MatrixRank, Identity)
{
    matrix::Matrix<float, 2, 2> matrix = {1.f, 0.f,
                                          0.f, 1.f};

    size_t result = matrix.rank();

    EXPECT_EQ(result, 2u);
}

TEST(MatrixRank, Simple)
{
    matrix::Matrix<float, 3, 4> matrix = {1.f, 2.f, 0.f, 0.f,
                                          2.f, 4.f, 0.f, 0.f,
                                         -1.f, 2.f, 1.f, 1.f};

    size_t result = matrix.rank();

    EXPECT_EQ(result, 2u);
}

TEST(MatrixRank, Complex)
{
    matrix::Matrix<float, 3, 4> matrix = { 8.f, 5.f,-2.f,
                                           4.f, 7.f,20.f,
                                           7.f, 6.f, 1.f,
                                          21.f,18.f, 7.f};

    size_t result = matrix.rank();

    EXPECT_EQ(result, 3u);
}

/***************************** */

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}