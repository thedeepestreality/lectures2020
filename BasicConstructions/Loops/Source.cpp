//calculation of the harmonic row sum
//1 + 1/2 + 1/3 + 1/4 + ...
#include <iostream>

int main()
{
	//size_t is synonim for unsigned int
	size_t max_num;
	std::cout << "Enter max num: ";
	std::cin >> max_num;
	size_t counter = 0;
	double sum = 0;

	//WHILE loop
	//Pre-condition
	while (++counter <= max_num)
		sum += 1. / counter;
	std::cout << "[ WHILE  ] Harmonic row sum: " << sum << '\n';
	sum = counter = 0;

	//WHILE loop
	//Post-condition
	do
	{
		sum += 1. / ++counter;
	}
	while (counter < max_num);
	std::cout << "[DO-WHILE] Harmonic row sum: " << sum << '\n';

	//FOR loop
	//master of the universe
	for (sum=0, counter = 0; 
		counter < max_num; 
		sum += 1. / ++counter);

	std::cout << "[  FOR   ] Harmonic row sum: " << sum << '\n';

	system("pause");
	return 0;
}