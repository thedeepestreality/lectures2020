#include <iostream>
#include "bubble_sort.h"
#include <ctime>
#include "utils.h"
#include "selection_sort.h"
#include "insertion_sort.h"

bool Less(double const& a, double const& b)
{
    return a < b;
}

//just an example on old-fashion
//time measurement
void test_bubble_sort()
{
    const int N = 500;
    double* arr = new double[N];
    gen_rand_array(arr, N);
    clock_t start = clock();
    bubble_sort(arr, N);
    clock_t finish = clock();
    std::cout << "Elapsed: " << 1000 * (double)(finish - start) / CLOCKS_PER_SEC << " ms\n";
}

template <typename Type>
void test_sort( const char sort_name[], 
                Sort<Type> sort, 
                Type const arr[], 
                size_t const Size, 
                Comparator<Type> comp = Greater<Type>)
{
    double* tmp = new double[Size];
    copy_array(arr, tmp, Size);
    tic();
    sort(tmp, Size, comp);
    std::cout << sort_name << " elapsed: " << toc() << " ms\n";
    delete[] tmp;
}

void dummy_test_sort(const char sort_name[],
    Sort<double> sort,
    Comparator<double> comp = Greater<double>)
{
    const int N = 10;
    double* arr = new double[N];
    gen_rand_array(arr, N);
    sort(arr, N, comp);
    std::cout << sort_name << " dummy test:\n";
    for (size_t idx = 0; idx < N; ++idx)
        std::cout << arr[idx] << ' ';
    std::cout << '\n';
}

int main()
{
    srand(time(NULL));
    const int N = 40000;
    double* arr = new double[N];
    gen_rand_array(arr, N);
    //test_sort("Bubble sort", bubble_sort, arr, N);
    //test_sort("Selection sort", selection_sort, arr, N);
    test_sort("Insertion sort", insertion_sort, arr, N);

    delete[] arr;

    return 0;
}