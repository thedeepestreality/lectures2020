#pragma once
#include "..\utils.h"
#include "insertion_sort.h"

template <typename Type>
size_t quick_sort_partition(Type arr[], 
                            size_t l_idx, 
                            size_t r_idx, 
                            Comparator<Type> comp = Greater,
                            Comparator<Type> eq = Equal)
{
    auto loose_ineq = [=](Type const& a, Type const& b) { return comp(a, b) || eq(a, b); };
    size_t pivot_idx = (l_idx + r_idx) / 2;
    Type const Pivot = arr[pivot_idx];
    while (l_idx < r_idx)
    {
        while (loose_ineq(Pivot, arr[l_idx]) && l_idx < pivot_idx)
            ++l_idx;
        while (loose_ineq(arr[r_idx], Pivot) && r_idx > pivot_idx)
            --r_idx;
        if (l_idx == r_idx) //!!!
            break;

        std::swap(arr[l_idx], arr[r_idx]);

        if (l_idx == pivot_idx)
            pivot_idx = r_idx;
        else if (r_idx == pivot_idx)
            pivot_idx = l_idx;
    }
    return l_idx;
}

template <typename Type>
void quick_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    if (Size <= 1)
        return;

    if (Size < 1e3)
    {
        insertion_sort(arr, Size, comp);
        return;
    }

    size_t const Pivot = quick_sort_partition(arr, 0, Size-1, comp);
    quick_sort(arr, Pivot, comp);
    quick_sort(arr + Pivot + 1, Size - Pivot - 1, comp);
}