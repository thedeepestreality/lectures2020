#include <iostream>
#include <stdarg.h>

int sum(int N, int x, ...)
{
    va_list args;
    va_start(args, x);
    int total_sum = x;
    while (--N)
        total_sum = va_arg(args, int);
    va_end(args);
    return total_sum;
}

double prod(double x, ...)
{
    va_list args;
    va_start(args, x);
    double total = x;
    while ((x = va_arg(args, double)) != 0)
        total *= x;
    va_end(args);
    return total;
}

int main()
{
    std::cout << "SUM: " << sum(3, 1, 2, 3) << '\n';
    std::cout << "PROD: " << prod(2, 3, 4, 0) << '\n';
    system("pause");
    return 0;
}