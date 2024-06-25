template<type T, size N>
class Vector
{
    Vector(const Vector& other);

    Vector &operator=(const Vector& other);

public:
    size_t size() { return N }
};