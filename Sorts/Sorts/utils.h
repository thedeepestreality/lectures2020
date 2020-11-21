#pragma once
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

static high_resolution_clock::time_point start;

void tic()
{
    start = high_resolution_clock::now();
}

long long toc()
{
    return duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
}

void gen_rand_array(double arr[], size_t const Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = (double)rand() / RAND_MAX;
}

template <typename Type>
void copy_array(Type source[], Type dest[], size_t const Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        dest[idx] = source[idx];
}

template <typename Type>
bool Greater(Type const& a, Type const& b)
{
    return a > b;
}