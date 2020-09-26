#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	const int Size = 10;
	const int MinVal = -10;
	const int MaxVal = 10;
	int min, max;
	double mean = 0;
	//Declare array;
	int arr[Size];

	//Filling array with random values
	for (size_t idx = 0; idx < Size; ++idx)
		arr[idx] = MinVal + rand() % (MaxVal - MinVal + 1);

	min = max = arr[0];
	for (size_t idx = 0; idx < Size; ++idx)
	{
		auto curr = arr[idx];
		max = ((curr > max) ? curr : max);
		min = ((curr < min) ? curr : min);
		mean += curr;
	}
	mean /= Size;

	//Printing array
	for (size_t idx = 0; idx < Size; ++idx)
		std::cout << arr[idx] << '\n';

	//Print statistics
	std::cout << "MIN: " << min << '\n';
	std::cout << "MAX: " << max << '\n';
	std::cout << "MEAN: " << mean << '\n';

	system("pause");
	return 0;
}