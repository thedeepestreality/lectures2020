#include <iostream>
//global variable
int z = 2;

int main()
{
	//allocate dynamic memory for single variable
	int* dyn_var = new int;
	//important! clean memory
	delete dyn_var;

	//now we can construct arrays with dynamic size
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	//allocate dynamic array
	int* px = new int[size];
	//copy pointer
	int* py = px;
	//you allocate new memory
	px = new int[2 * size];
	//important! clean dynamic arrays
	delete[] py;
	delete[] px;

	int x = 2;
	int* px = &x;
	//Pointer to pointer
	int** py = &px;

	//allocate dynamic 2D-array
	//allocate dynamic array of pointers
	int** arr_2d = new int* [size];
	//for each pointer allocate 1D dynamic array
	for (size_t i = 0; i < size; ++i)
		arr_2d[i] = new int[2 * size];

	//the same idea for 3D-array
	//or any-dimensional array
	int*** arr_3d = new int** [size];
	for (size_t i = 0; i < size; ++i)
	{
		arr_3d[i] = new int* [size];
		for (size_t j = 0; j < size; ++j)
			arr_3d[i][j] = new int[size];
	}
	//clean 2D array
	//first clean each of the 1D dynamic arrays
	for (size_t i = 0; i < size; ++i)
		delete[] arr_2d[i];
	//clean dynamic array of pointers
	delete[] arr_2d;

	//clean 3D-array
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
			delete[] arr_3d[i][j];
		delete[] arr_3d[i];
	}
	delete[] arr_3d;

	system("pause");
	return 0;
}