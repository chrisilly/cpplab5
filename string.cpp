#include "string.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    for (size_t i = 0; i < rhs.size(); i++)
    {
        out << rhs[i];
    }

    return out;
}

void String::Invariant()
{
    //assert(size <= capacity)
    assert(size() <= capacity());
    // add more asserts for everything that's true for a string class
}