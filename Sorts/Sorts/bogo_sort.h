#pragma once
template <class T>
void bogo_sort_like(T arr[], size_t const len, bool(*comp)(T const&, T const&) = Greater) {
    int i;
    while (true) {
        for (i = 1; i < len; i += 1)
            if (arr[i] < arr[i - 1])
                break;
        if (i == len)
            break;
        std::swap(arr[rand() % len], arr[rand() % len]);
    }
}