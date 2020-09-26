#include <iostream>

int main()
{
	char str[10] = "Hello";
	str[6] = 'O';
	char hell[] = { 'h','e','l','l' };
	std::cout << str << '\n';
	std::cout << hell << '\n';
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
	//std::cin.getline(sentence, 10);
	//std::cout << sentence << std::endl;

	std::cin.getline(sentence, 10, ',');
	std::cout << sentence << std::endl;
	
	system("pause");
	return 0;
}