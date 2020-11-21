#pragma once

template <typename Type>
void insertion_sort(Type arr[], size_t const Size, bool(*comp)(Type const&, Type const&) = Greater)
{
    for (size_t iter = 0; iter < Size - 1; ++iter)
    {
        Type key = arr[Size - iter - 2];
        size_t idx = Size - iter - 1;
        for (; idx < Size; ++idx)
        {
            if (arr[idx] < key)
                arr[idx - 1] = arr[idx];
            else
                break;
        }
        arr[idx-1] = key;
    }
}