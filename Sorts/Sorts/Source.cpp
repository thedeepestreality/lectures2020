#include <iostream>
#include <ctime>
#include "utils.h"
#include "sorts.h"

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
                SortFunc<Type> sort, 
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
    SortFunc<double> sort,
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

Sort<double> const sorts_array[] = {
   // {bubble_sort, "Bubble sort"},
   // {selection_sort, "Selection sort"},
    //{insertion_sort, "Insertion sort"},
    {merge_sort, "Merge sort"},
    {merge_sort_iter, "Merge sort iter"},
    {heap_sort, "Heap sort"}
};

void test_all_sorts(size_t const Size)
{
    double* arr = new double[Size];
    gen_rand_array(arr, Size);
    Comparator<double> comp = [](double const& a, double const& b) {return a < b; };
    for (auto const& sort : sorts_array)
        //test_sort(sort.name, sort.sort_func, arr, Size, Less);
        test_sort(sort.name, sort.sort_func, arr, Size, comp);
    delete[] arr;
}

int main()
{
    srand(time(NULL));
    test_all_sorts(1'000'000);
   // dummy_test_sort("Merge sort iter", merge_sort_iter);
    return 0;
}