#include <iostream>

int main()
{
	const int rows = 5;
	const int cols = 5;
	int array[rows][cols];
	int count = 0;
	//Fill
	for (int i = 0; i < rows; ++i)
	{
		bool even = (i % 2 == 0);
		int j = even ? 0 : (cols - 1);
		int increment = even ? 1 : -1;
		for (j; (j >= 0) && (j < cols); j += increment)
			array[i][j] = ++count;
	}
	//Print
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << array[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}