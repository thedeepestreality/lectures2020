#pragma once
#include "..\utils.h"

template <typename Type>
void insertion_sort(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
	for (size_t iter = 0; iter < Size - 1; ++iter)
	{
		Type key = arr[iter + 1];
		int idx = iter;
		for (; idx >= 0; --idx)
		{
			if (comp(arr[idx], key))
				arr[idx + 1] = arr[idx];
			else
				break;
		}
		arr[idx + 1] = key;
	}
}

//Insertion sort with binary search
template <typename Type>
void insertion_sort_bin(Type arr[], size_t const Size, Comparator<Type> comp = Greater)
{
	for (size_t iter = 0; iter < Size - 1; ++iter)
	{
		Type key = arr[iter + 1];
		size_t key_idx = binary_search_for_sort(arr, iter + 1, key, comp);
		int rightBound = key < arr[key_idx] ? key_idx : key_idx + 1;
		int idx = iter;
		for (; idx >= rightBound; --idx)
		{
			arr[idx + 1] = arr[idx];
		}
		arr[idx + 1] = key;
	}
}