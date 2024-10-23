#pragma once

#include <ostream>

struct A {

    int n;
    A() : n() {}
    A(int n) : n(n) {}

    A& operator+=(const A& other)
    {
        n += other.n;

        return *this;
    }

    A& operator-()
    {
        n = -n;

        return *this;
    }

    A operator*(const A& other) const
    {
        return A(n * other.n);
    }

    bool operator==(const A& other) const
    {
        return n == other.n;
    }

};

std::ostream& operator<<(std::ostream& os, const A& a)
{
    return os << a.n;
}