#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (auto const& val : v)
        std::cout << val << "\n";

    return 0;
}