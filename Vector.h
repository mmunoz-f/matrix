#include <utility>
#include <vector>
#include <ostream>
#include <cmath>

namespace matrix {

template<typename T>
class Matrix;

template<typename T>
class Vector
{
    typedef std::vector<T> vector_data;

    typedef typename vector_data::iterator iterator;
    typedef typename vector_data::const_iterator const_iterator;

    vector_data _data;

public:

/***
 * Constructors
 */

    Vector() :
        _data()
    {

    }

    explicit Vector(size_t size, const T& value = T()) :
        _data(size, value)
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

    Vector(const std::initializer_list<T>& init) :
        _data(init)
    {

    }

    Vector(const Matrix<T>& matrix) :
        _data()
    {
        _data.reserve(matrix.total_elements());

        for (auto column : matrix._data)
            for (T value : column)
            {
                _data.push_back(value);
            }
    }

    template<class _itetator>
    Vector(const _itetator& begin, const _itetator& end)
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

    Vector& operator=(const std::initializer_list<T>& init)
    {
        _data = init;

        return *this;
    }

    Vector& operator=(const Matrix<T>& matrix)
    {
        _data.clear();
        _data.reserve(matrix.total_elements());

        for (auto column : matrix._data)
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

/***
 * Access methods
 */

    inline const T& operator[](size_t pos) const
    {
        return _data[pos];
    }

    inline T&  operator[](size_t pos)
    {
        return _data[pos];
    }

    inline size_t size() const
    {
        return _data.size();
    }

    inline const_iterator begin() const
    {
        return _data.begin();
    }

    inline iterator begin()
    {
        return _data.begin();
    }

    inline const_iterator end() const
    {
        return _data.end();
    }

    inline iterator end()
    {
        return _data.end();
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

    T dot_product(const Vector& other) const
    {
        T result = T();

        for (size_t i = 0; i < size(); i++)
        {
            result = std::fma(_data[i], other[i], result);
        }

        return result;
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
            if (_data[i] != other[i])
                return false;
        }

        return true;
    }

    inline bool operator!=(const Vector& other) const
    {
        return !(*this == other);
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
Vector<T> operator*(const T& scalar, const Vector<T>& vector)
{
    return vector * scalar;
}

template<typename T, class container1, class container2>
Vector<T> linear_combination(const container1& vectors, const container2& coefs)
{
    size_t n_coefs = coefs.size();
    size_t dim = container2[0].size();
    Vector<T> result(dim);
    
    for (size_t i = 0; i < n_coefs; i++) // TODO: is this O(n)?
    {
        T acc = T();

        for (size_t j = 0; j < dim; j++)
        {
            acc = std::fma(vectors[j][i], coefs[j], acc);
        }

        result[i] = acc;
    }

    return result;
}

template<typename object>
inline Vector<float> lerp(const object& u, const object& v, const float scalar)
{
    return linear_combination<float>(Matrix({u, v}), Vector({1.f - scalar, scalar}));
}

}