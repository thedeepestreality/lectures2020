#pragma once
#include "utils.h"

template <typename Type>
void merge(Type arr[], size_t const Size, size_t const Split_idx, Comparator<Type> comp)
{
    size_t lpos = 0;
    size_t rpos = Split_idx;
    size_t tmp_pos = 0;
    Type* tmp_sorted = new Type[Size];

    while (lpos < Split_idx && rpos < Size)
        tmp_sorted[tmp_pos++] = comp(arr[lpos], arr[rpos]) ? arr[rpos++] : arr[lpos++];

    while (lpos < Split_idx)
        tmp_sorted[tmp_pos++] = arr[lpos++];

    while (rpos < Size)
        tmp_sorted[tmp_pos++] = arr[rpos++];

    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = tmp_sorted[idx];
    delete[] tmp_sorted;
}

template <typename Type>
void merge_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    if (Size == 1) 
        return;

    const size_t Split_idx = Size / 2;
    merge_sort(arr, Split_idx, comp);
    merge_sort(arr + Split_idx, Size - Split_idx, comp);
    merge(arr, Size, Split_idx, comp);
}
