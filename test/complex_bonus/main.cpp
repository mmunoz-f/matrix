#include <iostream>

#include <gtest/gtest.h>

#include "../../matrix.h"
#include "../../Complex.h"

#include "../test_utils.hpp"

/***
 * Complex
 */

TEST(ComplexEquality, Simple)
{
    matrix::Complex<float> complex1(2.f, 1.f);
    matrix::Complex<float> complex2(2.f, 1.f);

    expect_complex_float_eq(complex1, complex2);
}

TEST(ComplexAddition, Simple)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    matrix::Complex<float> result = complex1 + complex2;

    matrix::Complex<float> expect(4.f, 10.f);
    expect_complex_float_eq(result, expect);
}

TEST(ComplexAddition, SimpleAssign)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    complex1 += complex2;

    matrix::Complex<float> expect(4.f, 10.f);
    expect_complex_float_eq(complex1, expect);
}

TEST(ComplexSubstraction, Simple)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    matrix::Complex<float> result = complex1 - complex2;

    matrix::Complex<float> expect(-2.f, -2.f);
    expect_complex_float_eq(result, expect);
}

TEST(ComplexSubstraction, SimpleAssign)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    complex1 -= complex2;

    matrix::Complex<float> expect(-2.f, -2.f);
    expect_complex_float_eq(complex1, expect);
}

TEST(ComplexMultiplication, Simple)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    matrix::Complex<float> result = complex1 * complex2;

    matrix::Complex<float> expect(-21.f, 18.f);
    expect_complex_float_eq(result, expect);
}

TEST(ComplexMultiplication, SimpleAssign)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    complex1 *= complex2;

    matrix::Complex<float> expect(-21.f, 18.f);
    expect_complex_float_eq(complex1, expect);
}

TEST(ComplexDivision, Simple)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    matrix::Complex<float> result = complex1 / complex2;

    matrix::Complex<float> expect(3.f/5.f, 2.f/15.f);
    expect_complex_float_eq(result, expect);
}

TEST(ComplexDivision, SimpleAssign)
{
    matrix::Complex<float> complex1(1.f, 4.f);
    matrix::Complex<float> complex2(3.f, 6.f);

    complex1 /= complex2;

    matrix::Complex<float> expect(3.f/5.f, 2.f/15.f);
    expect_complex_float_eq(complex1, expect);
}

/**
 * EX00
 */

TEST(VectorComplexArithmetics, Addition)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Vector<matrix::Complex<float>, 2> vector2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix::Vector<matrix::Complex<float>, 2> result = vector1 + vector2;

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f)};
    expect_vector_complex_float_eq(result, expect);
}

TEST(VectorComplexArithmetics, AssignAddition)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Vector<matrix::Complex<float>, 2> vector2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    vector1 += vector2;

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f)};
    expect_vector_complex_float_eq(vector1, expect);
}

TEST(VectorComplexArithmetics, Substraction)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Vector<matrix::Complex<float>, 2> vector2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix::Vector<matrix::Complex<float>, 2> result = vector1 - vector2;

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f)};
    expect_vector_complex_float_eq(result, expect);
}

TEST(VectorComplexArithmetics, AssignSubstraction)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Vector<matrix::Complex<float>, 2> vector2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    vector1 -= vector2;

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f)};
    expect_vector_complex_float_eq(vector1, expect);
}

TEST(VectorComplexArithmetics, ScalarMultiplication)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f)};

    matrix::Vector<matrix::Complex<float>, 2> result = vector1 * matrix::Complex<float>(1, 4);

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f)};
    expect_vector_complex_float_eq(result, expect);
}

TEST(VectorComplexArithmetics, AssignScalarMultiplication)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f)};

    vector1 *= matrix::Complex<float>(1.f, 4.f);

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f)};
    expect_vector_complex_float_eq(vector1, expect);
}

TEST(VectorComplexArithmetics, ScalarDivision)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f)};

    matrix::Vector<matrix::Complex<float>, 2> result = vector1 / matrix::Complex<float>(3, 6);

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f)};
    expect_vector_complex_float_eq(result, expect);
}

TEST(VectorComplexArithmetics, AssignScalarDivision)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f)};

    vector1 /= matrix::Complex<float>(3.f, 6.f);

    matrix::Vector<matrix::Complex<float>, 2> expect = {matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f)};
    expect_vector_complex_float_eq(vector1, expect);
}

TEST(MatrixComplexArithmetics, Addition)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix::Matrix<matrix::Complex<float>, 2, 2> result = matrix1 + matrix2;

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f),
                                                           matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f)};
    expect_matrix_complex_float_eq(result, expect);
}

TEST(MatrixComplexArithmetics, AssignAddition)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix1 += matrix2;

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f),
                                                           matrix::Complex<float>(6.f, 8.f), matrix::Complex<float>(6.f, 8.f)};
    expect_matrix_complex_float_eq(matrix1, expect);
}

TEST(MatrixComplexArithmetics, Substraction)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix::Matrix<matrix::Complex<float>, 2, 2> result = matrix1 - matrix2;

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f),
                                                           matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f)};
    expect_matrix_complex_float_eq(result, expect);
}

TEST(MatrixComplexArithmetics, AssignSubstraction)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix2 = {matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f),
                                                            matrix::Complex<float>(3.f, 4.f), matrix::Complex<float>(3.f, 4.f)};

    matrix1 -= matrix2;

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f),
                                                           matrix::Complex<float>(0.f, 0.f), matrix::Complex<float>(0.f, 0.f)};
    expect_matrix_complex_float_eq(matrix1, expect);
}

TEST(MatrixComplexArithmetics, ScalarMultiplication)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f),
                                                            matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f)};

    matrix::Matrix<matrix::Complex<float>, 2, 2> result = matrix1 * matrix::Complex<float>(1, 4);

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f),
                                                           matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f)};
    expect_matrix_complex_float_eq(result, expect);
}

TEST(MatrixComplexArithmetics, AssignScalarMultiplication)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f),
                                                            matrix::Complex<float>(3.f, 6.f), matrix::Complex<float>(3.f, 6.f)};

    matrix1 *= matrix::Complex<float>(1, 4);

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f),
                                                           matrix::Complex<float>(-21.f, 18.f), matrix::Complex<float>(-21.f, 18.f)};
    expect_matrix_complex_float_eq(matrix1, expect);
}

TEST(MatrixComplexArithmetics, ScalarDivision)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f),
                                                            matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f)};

    matrix::Matrix<matrix::Complex<float>, 2, 2> result = matrix1 / matrix::Complex<float>(3, 6);

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f),
                                                           matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f)};
    expect_matrix_complex_float_eq(result, expect);
}

TEST(MatrixComplexArithmetics, AssignScalarDivision)
{
    matrix::Matrix<matrix::Complex<float>, 2, 2> matrix1 = {matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f),
                                                            matrix::Complex<float>(1.f, 4.f), matrix::Complex<float>(1.f, 4.f)};

    matrix1 /= matrix::Complex<float>(3, 6);

    matrix::Matrix<matrix::Complex<float>, 2, 2> expect = {matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f),
                                                           matrix::Complex<float>(3.f/5.f, 2.f/15.f), matrix::Complex<float>(3.f/5.f, 2.f/15.f)};
    expect_matrix_complex_float_eq(matrix1, expect);
}

/**
 * EX01
 */

TEST(ComplexLinearCombination, VectorSimple)
{
    matrix::Vector<matrix::Complex<float>, 2> vector1 = {matrix::Complex<float>(1.f, 0.f), matrix::Complex<float>(1.f, 0.f)};
    matrix::Vector<matrix::Complex<float>, 2> vector2 = {matrix::Complex<float>(0.f, 1.f), matrix::Complex<float>(0.f, 1.f)};

    matrix::Vector<matrix::Vector<matrix::Complex<float>, 2>, 2> vectors = { vector1, vector2 };
    matrix::Vector<int, 2> coefs = {2, 4};

    auto vector = matrix::linear_combination(vectors, coefs);

    matrix::Vector<matrix::Complex<float>, 2> expt = {matrix::Complex<float>(2.f, 4.f), matrix::Complex<float>(2.f, 4.f)};
    EXPECT_EQ(vector, expt);
}

/**
 * EX02
 */



/***************************** */

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}