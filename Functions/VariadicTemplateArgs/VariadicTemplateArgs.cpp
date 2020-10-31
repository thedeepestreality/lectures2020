#include <iostream>
#include "composition.h"

template <int arg1, int ... Args>
constexpr int Accumulate = arg1 + Accumulate<Args...>;

template<int arg1>
constexpr int Accumulate<arg1> = arg1;

template <int arg1, int ... Args>
constexpr int AccumulateSqr = arg1*arg1 + Accumulate<sqr(Args)...>;

template<int arg1>
constexpr int AccumulateSqr<arg1> = arg1*arg1;

template <typename TheOne>
void print_args(TheOne val)
{
    std::cout << val << '\n';
}

template <typename Head, typename ... Tail>
void print_args(Head head, Tail ... args)
{
    std::cout << head << '\n';
    print_args(args...);
}

int main()
{
    std::cout << compose<sqr, 3>(2) << '\n';
    std::cout << Accumulate<3, 6, -2, 100500> << '\n';
    print_args(1, 2.5, 'c', "string", false);
    return 1;
}