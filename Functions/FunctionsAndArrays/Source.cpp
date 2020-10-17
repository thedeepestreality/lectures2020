#include <iostream>

double mean(const int Arr[], const size_t Size)
{
    double sum = 0;
    for (size_t idx = 0; idx < Size; ++idx)
        sum += Arr[idx];
    return sum/Size;
}

int* new_array(const size_t Size)
{
    return new int[Size];
}

int** new_array(const size_t Rows, const size_t Cols)
{
    int** new_arr = new int* [Rows];
    for (size_t idx = 0; idx < Rows; ++idx)
        new_arr[idx] = new_array(Rows);
    return new_arr;
}

void delete_array(int* arr)
{
    delete[] arr;
}

void delete_array(int** arr, const size_t Rows)
{
    for (size_t idx = 0; idx < Rows; ++idx)
        delete_array(arr[idx]);
    delete[] arr;
}

void fill_random_array(    int* arr, 
                        const int Size, 
                        const int Lb, 
                        const int Ub)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = rand() % (Ub - Lb + 1) + Lb;
}

void fill_random_array( int** arr,
                        const int Rows,
                        const int Cols,
                        const int Lb,
                        const int Ub)
{
    for (size_t row = 0; row < Rows; ++row)
        fill_random_array(arr[row], Cols, Lb, Ub);
}

void print_array(const int* arr, const int Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << arr[idx] << '\t';
    std::cout << '\n';
}

void print_array(   const int** arr, 
                    const int Rows, 
                    const int Cols)
{
    for (size_t row = 0; row < Rows; ++row)
        print_array(arr[row], Cols);
    std::cout << '\n';
}

int main()
{
    const int Size = 3;
    int arr[Size] = { 1,2,3 };
    double mean_val = mean(arr, Size);
    std::cout << "MEAN VAL: " << mean_val << '\n';
    system("pause");
    return 0;
}