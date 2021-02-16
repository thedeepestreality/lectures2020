#include <iostream>

int main()
{
	char str[10] = "Hello";
	str[6] = 'O';
	char hell[] = { 'h','e','l','l' };
	std::cout << str << '\n';
	std::cout << hell << '\n';
	//modify str variabe through memory access
	hell[13] = 'W';
	std::cout << str << '\n';
	char str_copy[12];
	std::cout << strlen(str) << std::endl;
	strcpy_s(str_copy, str);
	std::cout << str_copy << std::endl;
	strcat_s(str_copy, str);
	std::cout << str_copy << std::endl;
	std::cout << strcmp(str, str_copy) << std::endl;
	//std::cout << str_copy[6] << std::endl;

	char sentence[64];
	std::cin.getline(sentence, 10);
	std::cout << sentence << std::endl;
	//check if string was more than 10 symbols
	//and read the rest
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.getline(sentence, 10);
	}
	//read until ',' symbol is met
	std::cin.getline(sentence, 10, ',');
	std::cout << sentence << std::endl;
	
	system("pause");
	return 0;
}