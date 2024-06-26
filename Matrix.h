#include <vector>

namespace matrix {

template<typename T>
class Matrix
{
    typename std::vector<T> column;
    typename std::vector<size_t> shape_t;

    std::vector<column> data;
    shape_t shape;

public:

    Matrix() :
        data(), // TODO are all vector empty initialized
        shape()
    {

    }
        
    Matrix(const Matrix& other) :
        data(data.other),
        shape(data.shape)
    {

    }

    // TODO Move contrusctor

    // TODO Matrix(range)

    ~Matrix()
    {
        // TODO careful! move semantif
    }

    Matrix &operator=(const Matrix& other)
    {
        if (this != &other)
        {
            data = other.data;
            shape = other.shape;
        }

        return *this;
    }

    // TODO Move operator

public:
    const shape_t &shape()
    {
        return shape;
    }
};

}