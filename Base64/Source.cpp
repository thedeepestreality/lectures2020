#include <iostream>
#include "base64.h"

int main()
{
	char str[] = "1234";
	char* encoded = base64_encode(str, strlen(str));
	std::cout << encoded << std::endl;

	return 0;
}