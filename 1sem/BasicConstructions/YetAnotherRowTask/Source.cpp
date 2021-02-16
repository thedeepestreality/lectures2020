#include <iostream>

int main()
{
	double x1 = 0.5;
	double x2 = 1.5;
	double dx = 0.1;
	const double magic = 1;
	double eps = 0.1;
	while (x1 < x2)
	{
		std::cout << x1;
		if (abs(x1 - magic) >= eps)
			std::cout << " magic!";
		std::cout << '\n';
		x1 += dx;
	}
	std::cout.precision(32);
	std::cout << (0.1 == (1.1 - 1)) << std::endl;
	std::cout << 0.1 << ' ' << 1.1 << ' ' << 1.1 - 1 << '\n';
	system("pause");
	return 0;
}