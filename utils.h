#pragma once

#include <array>
#include <cmath>

namespace matrix {

template<typename T>
T abs(T value)
{
    return (value > 0)? value : -value;
}

}