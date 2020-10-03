#include <iostream>

int main()
{
	double x1, x2, dx, eps;
	std::cout << "Enter x1 x2 dx eps: ";
	std::cin >> x1 >> x2 >> dx >> eps;
	double sum = 0;
	int n = 1;
	double term;
	std::cout << "x\tF(x)\tsin(x)\n";
	while (x1 <= x2)
	{
		term = x1;
		sum = 0;
		n = 1;
		do
		{
			sum += term;
			++n;
			term = -1 * term * x1 * x1 / ((2*n-1)*(2*n-2));
		} while (abs(term) >= eps);
		std::cout << x1 << ' ' << sum << ' ' << sin(x1) << '\n';
		x1 += dx;
	}

	system("pause");
	return 0;
}