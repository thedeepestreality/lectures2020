#pragma once
#include "utils.h"

template <class Type>
void bogo_sort_like(Type arr[], size_t const len, Comparator<Type> comp = Greater) {
    int i;
    while (true) {
        for (i = 1; i < len; i += 1)
            if (comp(arr[i-1], arr[i]))
                break;
        if (i == len)
            break;
        std::swap(arr[rand() % len], arr[rand() % len]);
    }
}