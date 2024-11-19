#include "string.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    std::cout << "Hello World!" << endl;

    // test constructor and `operator<<`
    String foo("FOO"), bar("BAR"), pie("PIE");
    cout << "foo: " << foo << endl;
    cout << "bar: " << bar << endl;
    cout << "pie: " << pie << endl;

    // test copy-constructor
    String foo2(foo);
    cout << "foo2: " << foo2 << endl;

    // test assignment operator
    foo = pie;
    pie = bar;
    cout << "foo: " << foo << endl;
    cout << "bar: " << bar << endl;
    cout << "pie: " << pie << endl;
    cout << "foo2: " << foo2 << endl;

    // test push_back
    for (size_t i = 0; i < 20; i++)
        foo2.push_back('A');
    
    cout << "foo2: " << foo2 << endl;
}