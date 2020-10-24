#include <iostream>

typedef double(*double_fun)(double);

double two(double x)
{
    return 2;
}

double my_fun(double x)
{
    return x * x + 2 * x;
}

int main()
{
    double(*fptr2)(double) = two;
    //double(*fptr)(double) = &my_fun;
    double_fun fptr = &my_fun;
    std::cout << "fptr2(10) = " << fptr2(10) << '\n';
    std::cout << "fptr(10) = " << fptr(10) << '\n';

    //double(*f_arr[3])(double) = { two, my_fun, sin };
    double_fun f_arr[3] = { two, my_fun, sin };
    for (size_t idx = 0; idx < 3; ++idx)
    {
        std::cout << "f_arr[" << idx << "](10) = ";
        std::cout << f_arr[idx](10) << '\n';
    }
    system("pause");
    return 0;
}