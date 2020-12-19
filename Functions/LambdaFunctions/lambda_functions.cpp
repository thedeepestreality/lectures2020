#include <iostream>

typedef double(*dfun)(double);

auto fun_sum(dfun f1, dfun f2)
{
    //return [f1, f2](double x) { return f1(x) + f2(x); };
    return [=](double x) { return f1(x) + f2(x); };
}

//y = a*x*x + b;

int main()
{
    auto f = fun_sum(sin, cos);
    auto f2 = fun_sum(sin, [](double x) { return x * x; });

    std::cout << f(0.7508) << '\n';

    double const c = 0.5;
    double b = 0;
    auto param_fun = [a = c, &b](double x) -> int { return a * x * x + b; };
    //[&](){};
    while (b < 10)
    {
        std::cout << param_fun(2) << '\n';
        b += 0.5;
    }

    return 0;
}