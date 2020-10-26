#include <iostream>

template <typename Type>
bool check_if_int()
{
    return false;
}

template <>
bool check_if_int<int>()
{
    return true;
}

template <typename Type>
void check_type()
{
    if (check_if_int<Type>())
        std::cout << "The type is int!\n";
    else
        std::cout << "The type is NOT int!\n";
}


int main()
{
    check_type<int>();
    check_type<double>();
    check_type<int*>();     //pointer to int is NOT int
    return 0;
}