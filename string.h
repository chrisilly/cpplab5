#ifndef STRING_H
#define STRING_H

#include <iostream>

class String 
{
char* content;

void Invariant();

public:

String();
String(const String& rhs);  // copy constructor
String(const char* cstring); // cstring ends with '\0'

String& operator=(const String& rhs); // Copy assignment operator
char& operator[](size_t i); // indexes without range check (?)
const char& operator[](size_t i) const; // indexes without range check (?)

size_t size() const; // amount of characters in the string
size_t capacity() const; // the character limit

void push_back(char character); // adds a character at the end

friend bool operator==(const String& lhs,
                        const String& rhs); // out of class definition

friend bool operator!=(const String& lhs,
                        const String& rhs); // out of class definition

/// @brief FOR TESTING PURPOSES ONLY
/// @return Gives a pointer to the array holding the String (does not end in '\0')
const char* data() const;

friend std::ostream& operator<<(std::ostream& out, const String& rhs);

~String(); // Deallocate heap memory

#pragma region PASSING WITH DISTINCTION

// indexing with range check 
// "Bounds checking is performed, exception of type std::out_of_range will be thrown on invalid access.”
char& at(size_t i);
const char& at(size_t i) const;

void reserve(size_t newCap); // See std::vector

void shrink_to_fit(); // should always do "shrink" if capacity != size

// concatenation
String& operator+=(const String& rhs);
String operator+(const String& rhs);

#pragma endregion
};

#endif