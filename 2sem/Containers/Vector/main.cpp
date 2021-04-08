#include <iostream>
#include "Vector.h"

struct Test {
    Test() { std::cout << "Hello!\n"; }
    ~Test() { std::cout << "Goodbye!\n"; }
};

int main()
{
    Vector<Test> vec;
    vec.push_back(Test());

    return 0;
}