#include <iostream>

int main()
{
	std::cout << "Enter Fahrenheit degrees: ";
	double fahrenheit;
	std::cin >> fahrenheit;
	//pay attention to 5./9
	//try to remove dot, see what happens
	double celsius = 5. / 9 * (fahrenheit - 32);
	//alternatives:
	//double celsius = (double)5/9*(fahrenheit-32);
	//double celsius = 5*(fahrenheit-32)/9;

	std::cout << "Celsius: " << celsius << '\n';
	if (celsius > 30)
		std::cout << "This is zharko!\n";
	else if (celsius < 15)
		std::cout << "This is holodno!\n";
	else
		std::cout << "This is normalno!\n";

	//Monster alternative using ternary condition operator
	//Be careful, young padavan! Use wisely.
	//std::cout << "This is ";
	//std::cout << ((celsius > 30) ? "hot" : ((celsius < 15) ? "cold" : "ok"));
	//std::cout << '\n';

	system("pause");
	return 0;
}