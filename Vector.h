template<type T>
class Vector
{
    Vector(const Vector& other);

    Vector &operator=(const Vector& other);

public:
    size_t size();
};