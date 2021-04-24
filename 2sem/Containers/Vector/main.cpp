#include <iostream>
#include "Vector.h"
#include <ctime>
#include "../String/String.h"

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

    Vector<String> vec;
    size_t const iter = 170000;
    
    String s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/";
    clock_t start = clock();
    for (size_t i = 0; i < iter; ++i)
        vec.push_back(s);
    std::cout << "Elapsed: " << 1000 * (double)(clock() - start) / CLOCKS_PER_SEC << "\n";

    return 0;
}