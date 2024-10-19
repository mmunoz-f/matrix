#pragma once

#include <array>
#include <cmath>

namespace matrix {

template<typename T>
T abs(T value)
{
    return (value > 0)? value : -value;
}

template<typename object>
inline object lerp(const object& u, const object& v, const float scalar)
{
    return v * scalar + u * (1 - scalar);
}

}