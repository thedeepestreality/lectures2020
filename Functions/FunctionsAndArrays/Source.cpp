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
        new_arr[idx] = new_array(Cols);
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

void fill_random_array( int* arr, 
                        const size_t Size,
                        const int Lb = -10, 
                        const int Ub = 10)
{
    for (size_t idx = 0; idx < Size; ++idx)
        arr[idx] = rand() % (Ub - Lb + 1) + Lb;
}

void fill_random_array( int** arr,
                        const size_t Rows,
                        const size_t Cols,
                        const int Lb = -10,
                        const int Ub = 10)
{
    for (size_t row = 0; row < Rows; ++row)
        fill_random_array(arr[row], Cols, Lb, Ub);
}

void print_array(const int* arr, const size_t Size)
{
    for (size_t idx = 0; idx < Size; ++idx)
        std::cout << arr[idx] << '\t';
    std::cout << '\n';
}

void print_array(   const int** Arr, 
                    const size_t Rows,
                    const size_t Cols)
{
    for (size_t row = 0; row < Rows; ++row)
        print_array(Arr[row], Cols);
    std::cout << '\n';
}

int* row_means( const int** Arr,
                const size_t Rows,
                const size_t Cols)
{
    int* means = new int[Rows];
    for (size_t row = 0; row < Rows; ++row)
    {
        means[row] = 0;
        for (size_t col = 0; col < Cols; ++col)
            means[row] += Arr[row][col];
        means[row] /= Cols;
    }
    return means;
}

void row_means(const int** Arr,
                const size_t Rows,
                const size_t Cols,
                int* means)
{
    for (size_t row = 0; row < Rows; ++row)
    {
        int sum = 0;
        for (size_t col = 0; col < Cols; ++col)
            sum += Arr[row][col];
        sum /= (int)Cols;
        means[row] = sum;
    }
}

int main()
{
    std::cout << "Enter Rows, Cols, Lb, Ub: ";
    size_t Rows, Cols;
    int Lb, Ub;
    std::cin >> Rows >> Cols >> Lb >> Ub;

    int** arr = new_array(Rows, Cols);
   // fill_random_array(arr, Rows, Cols, Lb, Ub);
    fill_random_array(arr, Rows, Cols);
    print_array((const int**)arr, Rows, Cols);

    int* means = new_array(Rows);
    row_means((const int**)arr, Rows, Cols, means);
    std::cout << "Array of row means: \n";
    print_array(means, Rows);
    delete_array(arr, Rows);
    delete_array(means);

    system("pause");
    return 0;
}