#include <iostream>
#include <ctime>
#include "utils.h"
#include "sorts.h"
#include <algorithm>

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
void test_sort( Sort<Type> const& sort, 
                Type const arr[], 
                size_t const Size)
{
    Type* arr_copy = new Type[Size];

    //Sort random
    copy_array(arr, arr_copy, Size);
    tic();
    sort.sort_func(arr_copy, Size, sort.comp);
    std::cout << sort.name << " [random] elapsed: " << toc() << " ms\n";

    //Sort sorted
    tic();
    sort.sort_func(arr_copy, Size, sort.comp);
    std::cout << sort.name << " [sorted] elapsed: " << toc() << " ms\n";

    //Sort reversed
    reverse_array(arr_copy, Size);
    tic();
    sort.sort_func(arr_copy, Size, sort.comp);
    std::cout << sort.name << " [reversed] elapsed: " << toc() << " ms\n";

    //Sort qsort killer
    quick_sort_killer_pretender(arr_copy, Size);
    tic();
    sort.sort_func(arr_copy, Size, sort.comp);
    std::cout << sort.name << " [q_killer] elapsed: " << toc() << " ms\n";

    delete[] arr_copy;
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
    // {heap_sort, "Heap sort"},
    {quick_sort, "Quick sort", GreaterOrEqual},
    {quick_sort_iter, "Quick sort iter", GreaterOrEqual}
    // {radix_sort, "Radix sort"}
};

template <typename Type>
void test_all_sorts(size_t const Size)
{
    Type* arr = new Type[Size];
    gen_rand_array(arr, Size);
    for (auto const& sort : sorts_array)
        test_sort(sort, arr, Size);
    delete[] arr;
}

void test_radix()
{
    size_t const Size = 10;
    int* arr = new int[Size];
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = 50-rand() % 100;
    radix_sort(arr, Size);
    std::cout << "Radix sort dummy test:\n";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << arr[idx] << ' ';
    std::cout << '\n';
    delete[] arr;
}

void test_qsort_killer()
{
    const int N = 10;
    double* arr = new double[N];
    std::cout << "qKiller dummy test:\n";
    quick_sort_killer_pretender(arr, N);
    for (size_t idx = 0; idx < N; ++idx)
        std::cout << arr[idx] << ' ';
    std::cout << '\n';
}

struct Point
{
    double x;
    double y;
};

void sort_points()
{
    const size_t Size = 5;
    Point pts[Size] = { 
        {1, 0.5}, 
        {1, 2}, 
        {0, 1}, 
        {-0.5, 0.1}, 
        {-1, 3} 
    };

    Point pts_copy[5];
    copy_array(pts, pts_copy, Size);

    std::cout << "Original:\n";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << '(' << pts[idx].x << ',' << pts[idx].y << "), ";
    std::cout << '\n';

    Comparator<Point> norm_comp = [](Point const& p1, Point const& p2) {
        double norm1 = sqrt(p1.x * p1.x + p1.y * p1.y);
        double norm2 = sqrt(p2.x * p2.x + p2.y * p2.y);
        return norm1 > norm2;
    };

    insertion_sort(pts_copy, Size, norm_comp);
    std::cout << "Norm sort:\n";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << '(' << pts_copy[idx].x << ',' << pts_copy[idx].y << "), ";
    std::cout << '\n';

    Comparator<Point> y_comp = [](Point const& p1, Point const& p2) {
        return p1.y > p2.y;
    };
    copy_array(pts, pts_copy, Size);
    insertion_sort(pts_copy, Size, y_comp);
    std::cout << "Y sort:\n";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << '(' << pts_copy[idx].x << ',' << pts_copy[idx].y << "), ";
    std::cout << '\n';

    copy_array(pts, pts_copy, Size);
    std::sort(pts_copy, pts_copy + Size, [](Point p1, Point p2) {return p1.x < p2.x; });
    std::cout << "X std::sort:\n";
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << '(' << pts_copy[idx].x << ',' << pts_copy[idx].y << "), ";
    std::cout << '\n';
}


int main()
{
    srand(time(NULL));
    //test_qsort_killer();
    //test_all_sorts<double>(2'000'000);
    //dummy_test_sort("Quick sort", quick_sort);
    //test_radix();
    sort_points();
    return 0;
}