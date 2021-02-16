#include <iostream>

typedef double(*double_fun)(double);

double two(double x)
{
    return 2;
}

double my_fun(double x)
{
    return 3* x * x + 2 * x;
}

double integrate(double a, double b, int N, double_fun func)
{
    double dx = (b - a) / N;
    double sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += dx * (func(a) + func(a + dx)) / 2;
        a += dx;
    }
    return sum;
}

int main()
{
    double(*fptr2)(double) = two;
    //double(*fptr)(double) = &my_fun;
    double_fun fptr = &my_fun;
    auto afptr = two;
    std::cout << "fptr2(10) = " << fptr2(10) << '\n';
    std::cout << "fptr(10) = " << fptr(10) << '\n';

    //double(*f_arr[3])(double) = { two, my_fun, sin };
    double_fun f_arr[3] = { two, my_fun, sin };
    std::cout << "INTEGRATIONS: \n";
    for (size_t idx = 0; idx < 3; ++idx)
    {
        std::cout << integrate(0, 1.5708, 100, f_arr[idx]) << '\n';
    }
    system("pause");
    return 0;
}