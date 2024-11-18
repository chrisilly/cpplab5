#ifndef STRING_H
#define STRING_H

#include <iostream>

class String 
{
size_t size;
size_t capacity;
char* text;

void Invariant();

public:

String();
String(const String& other);  // copy constructor
String(const char* value); // value ends with '\0'

String& operator=(const String& other); // Copy assignment operator
char& operator[](size_t i); // indexes without range check (?)
const char& operator[](size_t i) const; // indexes without range check (?)

size_t getSize() const; // amount of characters in the string
size_t getCapacity() const; // the character limit

void push_back(char character); // adds a character at the end

friend bool operator==(const String& value,
                        const String& other); // out of class definition

friend bool operator!=(const String& value,
                        const String& other); // out of class definition

/// @brief FOR TESTING PURPOSES ONLY
/// @return Gives a pointer to the array holding the String (does not end in '\0')
const char* data() const;

friend std::ostream& operator<<(std::ostream& out, const String& other);

~String(); // Deallocate heap memory

#pragma region PASSING WITH DISTINCTION

// indexing with range check 
// "Bounds checking is performed, exception of type std::out_of_range will be thrown on invalid access.”
char& at(size_t i);
const char& at(size_t i) const;

void reserve(size_t newCapacity); // See std::vector

void shrink_to_fit(); // should always do "shrink" if capacity != size

// concatenation
String& operator+=(const String& value);
String operator+(const String& value);

#pragma endregion
};

#endif