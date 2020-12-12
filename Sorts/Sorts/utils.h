#pragma once
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

static high_resolution_clock::time_point start;

template <typename Type>
using Comparator = bool(*)(Type const&, Type const&);

template <typename Type>
using SortFunc = void(*)(Type*, size_t const, Comparator<Type>);

template <typename Type>
struct Sort
{
    SortFunc<Type> sort_func;
    char const name[32];
    Comparator<Type> comp = Greater<Type>;
};

void tic()
{
    start = high_resolution_clock::now();
}

long long toc()
{
    return duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
}

template <typename Type>
void gen_rand_array(Type arr[], size_t const Size) {}

template <>
void gen_rand_array<double>(double arr[], size_t const Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = (double)rand() / RAND_MAX;
}

template <>
void gen_rand_array<int>(int arr[], size_t const Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = RAND_MAX/2 - rand();
}

template <typename Type>
void copy_array(Type const source[], Type dest[], size_t const Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        dest[idx] = source[idx];
}

template <typename Type>
inline bool Greater(Type const& a, Type const& b)
{
    return a > b;
}

template <typename Type>
bool Equal(Type const& a, Type const& b)
{
    return a == b;
}

template <typename Type>
inline bool GreaterOrEqual(Type const& a, Type const& b)
{
    return a >= b;
}