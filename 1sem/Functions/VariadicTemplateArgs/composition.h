#pragma once

typedef double(*dfun)(double);

double sqr(double val)
{
    return val * val;
}

template <dfun F, int N>
double compose(double val)
{
    return F(compose<F, N - 1>(val));
}

template <>
double compose<sqr, 1>(double val)
{
    return sqr(val);
}

//function recursion analog
double compose_rec(dfun f, int N, double val)
{
    if (N == 1)
        return f(val);
    return compose_rec(f, N - 1, val);
}