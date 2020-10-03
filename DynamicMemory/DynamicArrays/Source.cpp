#include <iostream>
int z = 2;

int main()
{
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	int* px = new int[size];
	int* py = px;
	px = new int[2 * size];

	delete[] py;
	delete[] px;
	//int x = 2;
	//int* px = &x;
	//int* py = &px;

	int** arr_2d = new int* [size];
	for (size_t i = 0; i < size; ++i)
		arr_2d[i] = new int[2 * size];

	int*** arr_3d = new int** [size];
	for (size_t i = 0; i < size; ++i)
	{
		arr_3d[i] = new int* [size];
		for (size_t j = 0; j < size; ++j)
			arr_3d[i][j] = new int[size];
	}

	for (size_t i = 0; i < size; ++i)
		delete[] arr_2d[i];
	delete[] arr_2d;
//	delete[] px;
	system("pause");
	return 0;
}