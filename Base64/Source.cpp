#include <iostream>
#include "base64.h"

int main()
{
	char str[] = "1234";
	char* encoded = base64Encode(str, strlen(str));
	std::cout << encoded << std::endl;
	system("pause");
	return 0;
}