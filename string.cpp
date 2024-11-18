#include "string.h"
#include <cassert>
#include <cstring>

String::String() : size(0), capacity(0), text(new char[1] {})
{ 
    Invariant();
}

String::String(const char* value) : size(strlen(value)), capacity(size + 10), text(new char[capacity] {})
{
    std::memcpy(text, value, size);

    Invariant();
}

/// @brief Copy-constructor
String::String(const String& other) : size(other.size), capacity(other.capacity), text(new char[capacity] {})
{
    std::memcpy(text, other.text, size);

    Invariant();
}

String& String::operator=(const String& other)
{
    Invariant();

    if(this == &other) return *this;
    
    if(capacity < other.size) 
    {
        delete[] text;
        this->capacity = other.capacity;
        text = new char[capacity];
    }

    this->size = other.size;
    std::memcpy(text, other.text, size);

    Invariant();    

    return *this;
}

void String::push_back(char character)
{
    Invariant();

    if(size == capacity)
        if(capacity == 0)
            reserve(1);
        else
            reserve(2 * capacity);

    text[size++] = character;

    Invariant();
}

void String::reserve(size_t newCapacity)
{
    assert(newCapacity > this->capacity);

    char* newData = new char[newCapacity];
    std::memcpy(newData, text, size);
    delete[] text;
    text = newData;
    capacity = newCapacity;
}

String::~String()
{
    Invariant();
    delete[] text;
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

std::ostream& operator<<(std::ostream& out, const String& other)
{
    for (size_t i = 0; i < other.size; i++)
    {
        out << other[i];
    }

    return out;
}

char& String::operator[](size_t i) { return text[i]; }
const char& String::operator[](size_t i) const { return text[i]; }

void String::Invariant()
{
    assert(size <= capacity);
    assert(size >= 0);
    assert(capacity >= 0);
    // add more asserts for everything that's true for a string class
}

size_t String::getSize() const { return size; }
size_t String::getCapacity() const { return capacity; }
const char* String::data() const { return text; }