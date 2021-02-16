#include <iostream>
#include "functions.h"

static int global_var = 4;

int main()
{
    //global_var = 3;
    //std::cout << ::global_var << std::endl;
    int num = 42;
    print_hello();
    print_num(num);
    int s = sum(1, 2);
    print_num(sum(2, 3));
    int x = 2;
    int y = 3;
    Swap(&x, &y);
    Swap(x, y);
    print_num(x);
    print_num(y);

    std::cout << mpow(2, -2) << '\n';

    for (int i = 0; i < 5; ++i)
        std::cout << count_calls() << '\n';
    system("pause");
    return 0;
}