#include <iostream>
#include "bubble_sort.h"
#include <ctime>
#include "utils.h"

bool Less(double const& a, double const& b)
{
    return a < b;
}

int main()
{
    srand(time(NULL));
    const int N = 500;
    double* arr = new double[N];
    gen_rand_array(arr, N);

 /*   clock_t start = clock();
    bubble_sort(arr, N);
    clock_t finish = clock();
    std::cout << "Elapsed: " << 1000*(double)(finish - start) / CLOCKS_PER_SEC << " ms\n";*/
    tic();
    bubble_sort(arr, N, Less);
    std::cout << "Elapsed: " << toc() << " ms\n";

    delete[] arr;

    return 0;
}