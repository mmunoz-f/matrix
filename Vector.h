#include <utility>
#include <vector>
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

/***
 * Constructors
 */

    Vector() :
        _data()
    {

    }

    Vector(size_t size) :
        _data(size)
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

/***
 * Assign operations
 */

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

/***
 * Move operations
 */

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

    inline const T& operator[](size_t pos) const
    {
        return _data[pos];
    }

    inline T&  operator[](size_t pos)
    {
        return _data[pos];
    }

/***
 * Arithmetics operations
 */

    Vector operator+(const Vector& other) const
    {
        Vector vector(size());
        
        for (size_t i = 0; i < size(); i++) // TODO: change to only make size one time or use literal when optimized
        {
            vector[i] = _data[i] + other[i];
        }

        return vector;
    }

    Vector& operator+=(const Vector& other)
    {
        for (size_t i = 0; i < size(); i++)
        {
            _data[i] += other[i];
        }

        return *this;
    }

    Vector operator-(const Vector& other) const
    {
        Vector vector(size());
        
        for (size_t i = 0; i < size(); i++)
        {
            vector[i] = _data[i] - other[i];
        }

        return vector;
    }

    Vector& operator-=(const Vector& other)
    {
        for (size_t i = 0; i < size(); i++)
        {
            _data[i] -= other[i];
        }

        return *this;
    }

    Vector operator*(const T& scalar) const
    {
        Vector vector(size());

        for (size_t i = 0; i < size(); i++)
        {
            vector[i] = _data[i] * scalar;
        }

        return vector;
    }

    Vector& operator*=(const T& scalar)
    {
        Vector vector(size());

        for (size_t i = 0; i < size(); i++)
        {
            _data[i] *= scalar;
        }

        return *this;
    }

/***
 * Equality operators
 */

    bool operator==(const Vector& other) const
    {
        if (size() != other.size())
            return false;
        
        for (size_t i = 0; i < size(); i++)
        {
            if (_data[i] != other._data[i])
                return false;
        }

        return true;
    }

    bool operator!=(const Vector& other) const
    {
        return !(*this == other);
    }

    inline size_t size() const
    {
        return _data.size();
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

template<typename T>
Vector<T> operator*(const int scalar, const Vector<T>& vector)
{
    return vector * scalar;
}

}