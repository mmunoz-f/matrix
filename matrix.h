#include "Vector.h"
#include "Matrix.h"

namespace matrix {

template<typename object>
inline object lerp(const object& u, const object& v, const float scalar) // TODO: check object::value_type == float or study decltype for aritmethics op
{
    return v * scalar + u * (1 - scalar);
}

template<typename T>
inline Vector<T> lerp(const Vector<T>& u, const Vector<T>& v, const float scalar)
{
    return linear_combination<float>(Vector<Vector<T> >({u, v}), Vector<float>({1 - scalar, scalar}));
}

template<typename T>
inline Matrix<T> lerp(const Matrix<T>& a, const Matrix<T>& b, const float scalar)
{
    Matrix<T> result(a.shape());
    const Vector<float> coefs({1 - scalar, scalar});

    for (size_t i = 0; i < result.shape().first; i++)
    {
        result[i] = linear_combination<float>(Vector<Vector<T> >({a[i], b[i]}), coefs);
    }

    return result;
}

}