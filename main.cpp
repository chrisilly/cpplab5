#include "string.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    std::cout << "Hello World!" << endl;

    // cout << "Size of a char: " << sizeof(char) << endl;

    String foo("FOO"), bar("BAR"), pie("PIE");
    cout << "foo: " << foo << endl;
    cout << "bar: " << bar << endl;
    cout << "pie: " << pie << endl;
    String foo2(foo);
    cout << "foo2: " << foo2 << endl;
    foo = pie;
    pie = bar;
    cout << "foo: " << foo << endl;
    cout << "bar: " << bar << endl;
    cout << "pie: " << pie << endl;
    cout << "foo2: " << foo2 << endl;

    // If we now change foo or bar, the other shouldn't be affected 
}