#include <iostream>

int main()
{
	const int rows = 4;
	const int cols = 5;
	int matrix[rows][cols];
	int currRow = 0, currCol = 0;
	int signR = 0, signC = 1;
	int nRows = rows, nCols = cols;
	int cTurn = nCols;
	int turnCount = 0, turnCountMod4 = 0;
	for (int i = 1; i <= rows * cols; ++i)
	{
		matrix[currRow][currCol] = i;
		if (i == cTurn)
		{
			++turnCount;
			turnCountMod4 = turnCount % 4;
			signR = 1 - abs(turnCountMod4 - 1);
			signC = abs(turnCountMod4 - 2) - 1;
			nCols -= abs(signC);
			nRows -= abs(signR);
			cTurn += !(signR == 0) * nRows + !(signC == 0) * nCols;
		}
		currRow += signR;
		currCol += signC;
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << '\t';
		std::cout << '\n';
	}

	system("pause");
	return 0;
}