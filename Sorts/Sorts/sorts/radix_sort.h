#pragma once

size_t radix_sort_partition(int arr[], size_t const Size, size_t const Digit)
{
    int const mask = 1 << Digit;
    size_t l_idx = 0;
    size_t r_idx = Size - 1;
    while (l_idx != r_idx)
    {
        while ((l_idx < r_idx) && !(arr[l_idx] & mask))
            ++l_idx;
        while ((r_idx > l_idx) && (arr[r_idx] & mask))
            --r_idx;
        if (l_idx != r_idx)
            std::swap(arr[l_idx], arr[r_idx]);
    }
    return (arr[l_idx] & mask) ? l_idx : l_idx + 1;
}

void radix_sort_rec(int arr[], size_t const Size, int const Digit = 8*sizeof(int)-1)
{
    if (Size <= 1)
        return;
    if (Digit < 0)
        return;
    size_t const Split_idx = radix_sort_partition(arr, Size, Digit);
    radix_sort_rec(arr, Split_idx, Digit - 1);
    radix_sort_rec(arr + Split_idx, Size - Split_idx, Digit - 1);
}

void radix_sort(int arr[], size_t const Size, Comparator<int> comp = Greater)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] ^= INT_MIN;

    radix_sort_rec(arr, Size);

    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] ^= INT_MIN;
}

void radix_sort_stable(int arr[], size_t const Size)
{
    for (int digit = 0; digit < 32; ++digit)
    {
        int mask = (1 << digit);
        for (size_t iter = 0; iter < Size - 1; ++iter)
        {
            int key = arr[iter + 1];
            int idx = iter;
            for (; idx >= 0; --idx)
            {
                if ((arr[idx] & mask) > (key & mask))
                    arr[idx + 1] = arr[idx];
                else
                    break;
            }
            arr[idx + 1] = key;
        }
    }
}
