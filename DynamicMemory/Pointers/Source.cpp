#include <iostream>

int main()
{
	int x = 5;
	int* px = &x;
	std::cout << "px val: " << px << '\n';
	std::cout << "sizeof(px): " << sizeof(px) << '\n';
	std::cout << "*px: " << *px << '\n';
	*px = 2;
	std::cout << "x: " << x << '\n';

	double y = 0.5;
	double* py = &y;
	std::cout << "py val: " << py << '\n';
	std::cout << "sizeof(py): " << sizeof(py) << '\n';
	std::cout << "*py: " << *py << '\n';
	//py = px; //error
	px = (int*)py;
	*px = 2'124'567'891;
	*(px + 1) = 1568; 
	//*py = 0.6;
	std::cout << "y: " << y << '\n';
	int arr[5] = { 1,2,3,4,5 };
	int* p_arr = arr;
	*(p_arr + 1) = 10; // equal: p_arr[1] = 10;
	*(arr + 3) = 20; //equal: arr[3] = 20;
	//equal expressions
	std::cout << arr[1] << std::endl;
	std::cout << 1[arr] << std::endl;
	std::cout << *(arr+1) << std::endl;

	//decompose int varaible
	//to the array of 4 chars
	int val = 769;
	//get addres of val and cast to char pointer
	char* pc = (char*)&val;
	std::cout << (int)pc[0] << '\n';
	std::cout << (int)pc[1] << '\n';
	std::cout << (int)pc[2] << '\n';
	std::cout << (int)pc[3] << '\n';

	//reverse operation
	//compose int variable from 4-char array
	char c_arr[4] = { 1,3,0,0 };
	int* int_from_char = (int*)c_arr;
	std::cout << *int_from_char << '\n';

	system("pause");
	return 0;
}