#include <iostream>

int main()
{
	std::cout << "Enter number: ";
	unsigned int day;
	std::cin >> day;
	//GOTO is a no-no!
	//goto label2;

	//SWITCH-CASE construction can set individual actions
	//for each value of the integer variable
	switch (day)
	{
		//remember to put break in the end!
		case 0: std::cout << "Mon\n" ; break;
		case 1: std::cout << "Tue\n" ; break;
		case 2: std::cout << "Wed\n" ; break;
		case 3: std::cout << "Thur\n"; break;
		//if we forget break here,
		//output will be "Fri\nSat\n"
		case 4: std::cout << "Fri\n" ;
		case 5: std::cout << "Sat\n" ; break;
		case 6: std::cout << "Sun\n" ; break;
		//if above cases didn't work, we will fall to default case
		default: std::cout << "Wrong number\n"; break;
	}

//GOTO will go here
//label2:
//	int x = 2;

	system("pause");
	return 0;
}