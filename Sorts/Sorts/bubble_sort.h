#pragma once
#include "utils.h"

template <typename Type>
void bubble_sort(Type arr[], size_t const size, bool(*comp)(Type const&, Type const&) = Greater)
{
    for (size_t iter = 1; iter < size; ++iter)
        for (size_t idx = 0; idx < size - iter; ++idx)
            if (comp(arr[idx], arr[idx + 1]))
                std::swap(arr[idx], arr[idx + 1]);
}

//size-1
//size-2
//size-3
// (1 + size-1)*(size-1)/2 = size*(size-1)/2 = (size^2 - size)/2
// (size^2 - size)
// f(n) g(n)
// f(n) = O(g(n))
// f(n) <= c*g(n)  n > n0
// O(n^2)