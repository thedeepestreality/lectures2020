#include <iostream>
#include "Vector.h"

struct Test {
    Test() { std::cout << "Hello!\n"; }
    ~Test() { std::cout << "Goodbye!\n"; }
};

int main()
{
    Advanced::Vector<Test> vec(3);
   // vec.push_back(Test());
    vec.reserve(5);
    vec.push_back(Test());

    return 0;
}