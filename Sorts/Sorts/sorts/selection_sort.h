#pragma once
#include "utils.h"

template <typename Type>
void selection_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    for (size_t iter = 0; iter < Size - 1; ++iter)
    {
        size_t max_idx = 0;
        for (size_t idx = 1; idx < Size - iter; ++idx)
            if (comp(arr[idx], arr[max_idx]))
                max_idx = idx;
        std::swap(arr[max_idx], arr[Size - iter - 1]);
    }
}