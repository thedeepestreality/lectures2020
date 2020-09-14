// plain simple hello world example

//including input-output library
#include <iostream>

//bad: could lead to name ambiguation
//using namespace std;

/*
	acceptable:
	using std::cout;
	using std::cin;
*/

//main function is mandatory
//this is the entry point of the program
int main()
{
	//cout -- console output stream
	//using endl as new line could be slow
	std::cout << "Hello world!\n"; // << std::endl;
	//iteger variable
	int val;
	std::cout << "Input integer value: ";
	//read integer value from the console
	std::cin >> val;
	//stream handles conversion of variables to strings
	std::cout << "You entered " << val << '\n';

	//to avoid closing of the console window
	system("pause");
	//return error code
	//0 if success
	return 0;
}