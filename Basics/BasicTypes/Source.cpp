#include <iostream>

//typedef specifier allows to rename a type
typedef const unsigned long long int c_ull_i;
int main()
{
	//Decimal integer
	int dec = 42;
	//Octal integer
	int oct = 052;
	//Hexadecimal
	int hex = 0x2a;
	int HEX = 0X2A;
	//Binary (since C++14)
	int bin = 0b101010;

	double dbl_val = 1.6;
	//or: dbl_val = 16e-1
	//or: dbl_val = 1.6e0

	//conversion to int destroys non-integer part
	int dbl_to_int = dbl_val;

	std::cout << "Values: " << dec << ' ' << oct << ' ' << hex;
	std::cout << ' ' << HEX << ' ' << bin;
	std::cout << dbl_val << ' ' << dbl_to_int << '\n';

	int biiig_val = 2'000'000; //C++11 new cool feature!

	//sizeof operator can tell you the size of the type in bytes
	std::cout << "Size of int: " << sizeof(biiig_val) << '\n';
	std::cout << "Size of long: " << sizeof(long) << '\n';
	std::cout << "Size of long long: " << sizeof(long long) << '\n';
	std::cout << "Size of short: " << sizeof(short) << '\n';
	std::cout << "Size of char: " << sizeof(char) << '\n';
	std::cout << "Size of float: " << sizeof(float) << '\n';
	std::cout << "Size of double: " << sizeof(double) << '\n';
	std::cout << "Size of bool: " << sizeof(bool) << '\n';

	//examples of cyclic overflows
	unsigned char ubyte = -2;
	std::cout << "Unsigned val: " << (int)ubyte << '\n';
	signed char byte = 128;
	std::cout << "Ssigned val: " << (int)byte <<'\n';

	//constants
	const int const_x = 1;
	//const_x = 2; //error: forbidden to change const values

	system("pause");
	return 0;
}