#include <iostream>

template <typename Type>
Type mean(const Type Arr[], const size_t Size)
{
    Type sum = 0;
    for (size_t idx = 0; idx < Size; ++idx)
        sum += Arr[idx];
    return sum/Size;
}

//int (*m)(const int* const, const size_t) = mean;
auto fptr = mean<int>;

template <typename Type>
Type* new_array(const size_t Size)
{
    return new Type[Size];
}

template <typename Type>
Type** new_array(const size_t Rows, const size_t Cols)
{
    Type** new_arr = new Type * [Rows];
    for (size_t idx = 0; idx < Rows; ++idx)
        new_arr[idx] = new_array<Type>(Cols);
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
        means[row] = mean(Arr[row], Cols);
    return means;
}

void row_means(const int** Arr,
                const size_t Rows,
                const size_t Cols,
                int* means)
{
    for (size_t row = 0; row < Rows; ++row)
        means[row] = mean(Arr[row], Rows);
}

template <class Type>
void dummy_fun(Type ptr1, Type ptr2)
{
    Type ptr3 = ptr1 + ptr2;
}

//auto fptr_df = dummy_fun<int*>;

template <int N>
void calc(int x)
{
    //N = 10;
}

template <typename Type, typename T2 = double>
void _pow(Type x, T2 deg)
{
    std::cout << "General case\n";
}

template <>
void _pow(int x, int deg)
{
    std::cout << "Int case\n";
}

int main()
{
    _pow(int(1), double(2.0));
    calc<10>(2);
    std::cout << "Enter Rows, Cols, Lb, Ub: ";
    size_t Rows, Cols;
    int Lb, Ub;
    std::cin >> Rows >> Cols >> Lb >> Ub;

    int** arr = new_array<int>(Rows, Cols);
   // fill_random_array(arr, Rows, Cols, Lb, Ub);
    fill_random_array(arr, Rows, Cols, Lb);
    print_array((const int**)arr, Rows, Cols);

    int* means = new_array<int>(Rows);
    row_means((const int**)arr, Rows, Cols, means);
    std::cout << "Array of row means: \n";
    print_array(means, Rows);
    delete_array(arr, Rows);
    delete_array(means);

    system("pause");
    return 0;
}