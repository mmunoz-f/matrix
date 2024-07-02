#include <utility>
#include <vector>
#include <algorithm>
#include <ostream>

namespace matrix {

template<typename T>
class Matrix;

template<typename T>
class Vector
{
    typedef std::vector<T> vector_data;

    vector_data _data;

public:
    Vector() :
        _data()
    {

    }

    Vector(const Vector& other) :
        _data(other._data)
    {

    }

    Vector(const vector_data& data) :
        _data(data)
    {

    }

    Vector(const Matrix<T>& matrix) :
        _data()
    {
        _data.reserve(matrix.total_elements());

        for (auto column : matrix.data)
            for (T value : column)
            {
                _data.push_back(value);
            }
    }

    template<class itetator>
    Vector(const itetator& begin, const itetator& end)
    {
        _data = vector_data(begin, end);
    }

    Vector(Vector&& other) :
        _data(std::move(other._data))
    {

    }

    Vector(vector_data&& data) :
        _data(std::move(data))
    {

    }

    ~Vector()
    {

    }

    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            _data = other._data;
        }

        return *this;
    }

    Vector& operator=(const vector_data& data)
    {
        _data = data;

        return *this;
    }

    Vector& operator=(const Matrix<T>& matrix)
    {
        _data.clear();
        _data.reserve(matrix.total_elements());

        for (auto column : matrix.data)
            for (T value : column)
            {
                _data.push_back(value);
            }
    }

    Vector& operator=(Vector&& other)
    {
        if (this != &other)
        {
            _data = std::move(other._data);
        }

        return *this;
    }

    Vector& operator=(vector_data&& data)
    {
        _data = std::move(data);

        return *this;
    }

    Vector operator+(const Vector& other) const
    {
        Vector<T> vector = std::transform(_data.begin(), _data.end(),
                                          other._data.begin(), other._data.end(),
                                          std::plus<T>());
        return vector;
    }

    Vector& operator+=(const Vector& other)
    {
        _data = std::transform(_data.begin(), _data.end(),
                               other._data.begin(), other._data.end(),
                               std::plus<T>());
    }

    Vector operator-(const Vector& other) const
    {
        Vector<T> vector = std::transform(_data.begin(), _data.end(),
                                          other._data.begin(), other._data.end(),
                                          std::minus<T>());
        return vector;
    }

    Vector& operator-=(const Vector& other)
    {
        _data = std::transform(_data.begin(), _data.end(),
                               other._data.begin(), other._data.end(),
                               std::minus<T>());
    }

    size_t size() const
    {
        return _data->size();
    }

    friend Matrix<T>;

    template<typename t>
    friend std::ostream& operator<<(std::ostream& os, const Vector<t>& vector);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector)
{
    os << "( ";
    
    for (T value : vector._data)
    {
        os << value << " ";
    }

    os << ")";
    return os;
}

}