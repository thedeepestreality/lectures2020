#include <iostream>

int factorial_iter(int n)
{
    int fact = 1;
    while (n > 1)
        fact *= n--;
    return fact;
}

int factorial_recursive(int n)
{
    if (n < 2)
        return 1;
    return n * factorial_recursive(n - 1);
}

void hanoi(size_t size, size_t from = 1, size_t to = 2, size_t tmp = 3)
{
    if (size == 1)
    {
        std::cout << from << "->" << to << '\n';
        return;
    }
    hanoi(size - 1, from, tmp, to);
    hanoi(1, from, to);
    hanoi(size - 1, tmp, to, from);
}

int main()
{
    int n = 5;
    std::cout << "Fact iter: " << factorial_iter(n) << '\n';
    std::cout << "Fact rec: " << factorial_recursive(n) << '\n';
    hanoi(3);
    system("pause");
    return 0;
}