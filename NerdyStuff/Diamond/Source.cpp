#include <iostream>

int main()
{
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	for (int row = 1; row <= size; ++row)
	{
		double half = (size + 1) / 2.0;
		int stars = 2 * (half - abs(half - row)) - 1;
		for (int col = 0; col < (size + stars) / 2; ++col)
			std::cout << (col < (size - stars) / 2 ? " " : "*");
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}