#include <iostream>

int main()
{
	const int Rows = 4;
	const int Cols = 6;
	int snake[Rows][Cols];
	int currVal = 1;
	//Filling array
	for (size_t row = 0; row < Rows; ++row)
	{
		//Forward
		if (row % 2 == 0)
			for (size_t col = 0; col < Cols; ++col)
				snake[row][col] = currVal++;
		//Backward
		else
			for (int col = Cols - 1; col >= 0; --col)
				snake[row][col] = currVal++; 
	}

	//Printing array
	for (size_t row = 0; row < Rows; ++row)
	{
		for (size_t col = 0; col < Cols; ++col)
			std::cout << snake[row][col] << '\t';
		std::cout << '\n';
	}

	system("pause");
	return 0;
}