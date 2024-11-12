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

/***************************** */

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}