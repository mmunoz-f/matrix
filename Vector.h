#include <vector>


namespace matrix {

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

    Vector(const Vector&& other) :
        data(other.data)
    {
        other.data = vector_data(); // TODO is this the best solution? data should be a pointer maybe
    }

    template<class itetator>
    Vector(const itetator& begin, const itetator& end) :
        data(begin, end)
    {

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

    // TODO Move operator 

    size_t size()
    {
        return data.size();
    }
};

}