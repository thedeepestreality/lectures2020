#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (auto const& val : v)
        std::cout << val << " ";
    std::cout << "\n";

    Vector<bool> vec_bool;
    vec_bool.push_back(1);
    vec_bool.push_back(0);
    vec_bool.push_back(1);
    vec_bool.push_back(1);

    for (size_t idx = 0; idx < vec_bool.size(); ++idx)
        std::cout << vec_bool[idx] << " ";
    std::cout << "\n";

    vec_bool[1] = 1;
    vec_bool[2] = 0;

    for (size_t idx = 0; idx < vec_bool.size(); ++idx)
        std::cout << vec_bool[idx] << " ";
    std::cout << "\n";

    return 0;
}