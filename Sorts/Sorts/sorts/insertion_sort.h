#pragma once
#include "..\utils.h"

template <typename Type>
void insertion_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    for (size_t iter = 0; iter < Size - 1; ++iter)
    {
        Type key = arr[Size - iter - 2];
        size_t idx = Size - iter - 1;
        for (; idx < Size; ++idx)
        {
            if (comp(key, arr[idx]))
                arr[idx - 1] = arr[idx];
            else
                break;
        }
        arr[idx-1] = key;
    }
}