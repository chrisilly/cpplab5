#include "string.h"
#include <cassert>
#include <cstring>

String::String() {}

String::String(const char* value)
{
    size = strlen(value);
    capacity = size + 10;
    text = new char[capacity];
    
    std::memcpy(text, value, size);
}

/// @brief Copy-constructor
String::String(const String& other) { *this = other; }

String& String::operator=(const String& other)
{
    // if(capacity < other.size) {}
    
    delete[] text;
    this->capacity = other.capacity;
    text = new char[capacity];

    this->size = other.size;
    std::memcpy(text, other.text, size);
    
    return *this;
}

String::~String()
{
    // delete[] text;
}

bool operator==(const String& value, const String& other)
{
    if(value.size != other.size) return false;
    // if(value.capacity != other.capacity) return false;

    for (int i = 0; i < value.size; i++)
        if(value[i] != other[i])
            return false;

    return true;
}

bool operator!=(const String& value, const String& other) { return !(value==other); }

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    for (size_t i = 0; i < rhs.size; i++)
    {
        out << rhs[i];
    }

    return out;
}

char& String::operator[](size_t i) { return text[i]; }
const char& String::operator[](size_t i) const { return text[i]; }

void String::Invariant()
{
    assert(size <= capacity);
    // add more asserts for everything that's true for a string class
}

size_t String::getSize() const { return size; }
size_t String::getCapacity() const { return capacity; }
const char* String::data() const { return text; }