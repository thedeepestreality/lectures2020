#pragma once
#include <chrono>
#include <iostream>

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
void reverse_array(Type source[], size_t const Size)
{
    for (size_t idx = 0; idx < Size / 2; ++idx)
        std::swap(source[idx], source[Size - idx - 1]);
}

template <typename Type>
void quick_sort_killer_pretender(Type Array[], size_t const Size)
{
    size_t* orig_idx = new size_t[Size];
    for (size_t idx = 0; idx < Size; ++idx)
        orig_idx[idx] = idx;

    size_t r_idx = Size - 1;

    for (size_t l_idx = 0; l_idx < r_idx; ++l_idx)
    {
        size_t pivot_idx = (r_idx + l_idx) / 2;
        std::swap(orig_idx[l_idx], orig_idx[pivot_idx]);
    }

    for (size_t i = 0; i < Size; i++)
    {
        size_t idx = orig_idx[i];
        Array[idx] = (Type)i / Size;
    }

    delete[] orig_idx;
}


template <typename Type>
int find(Type const arr[], size_t const Size, Type const& val)
{
    int val_idx = -1;
    for (size_t idx = 0; idx < Size; ++idx)
        if (arr[idx] == val)
        {
            val_idx = idx;
            break;
        }
    return val_idx;
}

template <typename Type>
int binary_search_recursive(Type arr[], size_t const size, Type const& val)
{
    if (size == 0) 
        return -1;

    int middle = size / 2;

    if (arr[middle] == val)
        return middle;

    if (arr[middle] > val)
        return binary_search_recursive(arr, middle, val);

    int idx = binary_search_recursive(arr + middle + 1, size - middle - 1, val);
    return idx >= 0 ? middle + 1 + idx : -1;
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