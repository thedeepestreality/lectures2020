#include <iostream>
#include "functions.h"

int main()
{
	global_var = 3;
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
	system("pause");
	return 0;
}