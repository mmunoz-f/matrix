#include <utility>
#include <vector>

namespace matrix {

template<typename T>
class Matrix;

template<typename T>
class Vector
{
    typename std::vector<T> vector_data;

    vector_data data;

public:
    Vector() :
        data()
    {

    }

    Vector(const Vector& other) :
        data(other.data)
    {

    }

    Vector(const vector_data& input_data) :
        data(input_data)
    {

    }

    Vector(const Matrix<T>& matrix) :
        data()
    {
        data.reserve(matrix.total_elements());

        for (auto column : matrix.data)
            for (T value : column)
            {
                data.push_back(value);
            }
    }

    Vector(Vector&& other) :
        data(std::move(other.data))
    {

    }

    template<class itetator>
    Vector(const itetator& begin, const itetator& end)
    {
        data = vector_data(begin, end)
    }

    ~Vector()
    {

    }

    Vector &operator=(const Vector& other)
    {
        if (this != &other)
        {
            data = other.data;
        }

        return *this;
    }

    Vector &operator=(Vector&& other)
    {
        if (this != &other)
        {
            data = std::move(other.data);
        }

        return *this;
    }

    Vector &operator=(const Matrix<T>& matrix)
    {
        data.clear();
        data.reserve(matrix.total_elements());

        for (auto column : matrix.data)
            for (T value : column)
            {
                data.push_back(value);
            }
    }

    size_t size() const
    {
        return data->size();
    }

    friend Matrix<T>;
};

}