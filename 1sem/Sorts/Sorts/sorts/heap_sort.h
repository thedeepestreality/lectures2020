#pragma once
#include "..\utils.h"

template <typename Type>
void heap_elem(Type arr[], size_t const Size, size_t idx, Comparator<Type> comp = Greater)
{
    size_t left_child = idx * 2 + 1;
    while (left_child < Size)
    {
        size_t right_child = left_child + 1;
        if (right_child >= Size)
        {
            if (comp(arr[left_child], arr[idx]))
                std::swap(arr[left_child], arr[idx]);
            break;
        }
        else
        {
            size_t const max_idx = comp(arr[left_child], arr[right_child]) ? left_child : right_child;
            if (comp(arr[max_idx], arr[idx]))
            {
                std::swap(arr[max_idx], arr[idx]);
                idx = max_idx;
                left_child = 2 * idx + 1;
            }
            else
                break;
        }
    }
}

template <typename Type>
void heap_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    //1. Make heap
    for (int idx = Size / 2 - 1; idx >= 0; --idx)
        heap_elem(arr, Size, idx, comp);

    //2. Sort
    for (size_t iter = 0; iter < Size - 1; ++iter)
    {
        std::swap(arr[0], arr[Size - iter - 1]);
        heap_elem(arr, Size - iter - 1, 0, comp);
    }
}