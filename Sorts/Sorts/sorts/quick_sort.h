#pragma once
#include "..\utils.h"
#include "insertion_sort.h"
#include <iostream>

template <typename Type>
int quick_sort_partition(Type arr[], 
                            int l_idx, 
                            int r_idx, 
                            Comparator<Type> comp = Greater,
                            Comparator<Type> eq = Equal)
{
    size_t pivot_idx = (l_idx + r_idx) / 2;
    Type const Pivot = arr[pivot_idx];
    while (l_idx < r_idx)
    {
        while (GreaterOrEqual(Pivot,arr[l_idx]) && l_idx < pivot_idx)
            ++l_idx;
        while (GreaterOrEqual(arr[r_idx], Pivot) && r_idx > pivot_idx)
            --r_idx;
        if (l_idx >= r_idx) //!!!
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

//Iterative quick sort
template <typename Type>
void quick_sort_iter(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
    // Create an auxiliary stack 
    int* stack = new int[Size];

    // initialize top of stack 
    int top = -1;
    int l_idx = 0;
    int r_idx = Size - 1;
    // push initial values of l and h to stack 
    stack[++top] = l_idx;
    stack[++top] = r_idx;

    // Keep popping from stack while is not empty 
    while (top > 0) {
        // Pop h and l 
        r_idx = stack[top--];
        l_idx = stack[top--];

        // Set pivot element at its correct position 
        // in sorted array 
        int const Pivot = quick_sort_partition(arr, l_idx, r_idx);

        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (Pivot - 1 > l_idx) {
            stack[++top] = l_idx;
            stack[++top] = Pivot - 1;
        }

        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (Pivot + 1 < r_idx) {
            stack[++top] = Pivot + 1;
            stack[++top] = r_idx;
        }
    }
    delete[] stack;
}