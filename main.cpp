#include <iostream>

#include "Vector.h"
#include "Matrix.h"

int main()
{
    matrix::Vector<int> vector1({1, 2, 3});

    matrix::Vector<int> vector2 = vector1 + vector1;
    
    matrix::Matrix<int> matrix({{1, 2, 3}, {1, 2, 3}, {1, 2, 3}});

    std::cout << vector2 << std::endl;
    std::cout << matrix << std::endl;
}