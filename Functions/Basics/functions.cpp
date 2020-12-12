#include <iostream>
#include "functions.h"

int global_var = 3;

void print_hello()
{
    std::cout << "Hello\n";
}

void print_num(const int num)
{
    int global_var = 3;
    int var = sum(5, 6);
    //return;
    std::cout << num << '\n';
    //num = 24;
    global_var = 3;
    ::global_var = 4;
}

int sum(int a, int b)
{
    return a + b;
}

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

double mpow(double val, int deg)
{
    double p = 1.0;
    if (deg >= 0)
        while (deg-- > 0)
            p *= val;
    else
        while (deg++ < 0)
            p /= val;
    return p;
}

int mpow(int val, int deg)
{
    return mpow((double)val, deg);
}

double mpow(double val, double deg)
{
    return exp(deg * log(fabs(val)));
}

int count_calls()
{
    static int n = 0;
    return ++n;
}
