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
	*(p_arr + 1) = 10;
	*(arr + 3) = 20;
	std::cout << 1[arr] << std::endl;
	std::cout << arr[3] << std::endl;
	char* pc = (char*)&x;
	x = 769;
	std::cout << (int)pc[0] << '\n';
	std::cout << (int)pc[1] << '\n';
	std::cout << (int)pc[2] << '\n';
	std::cout << (int)pc[3] << '\n';

	char c_arr[4] = { 1,3,0,0 };
	int* int_from_char = (int*)c_arr;
	std::cout << *int_from_char << '\n';

	system("pause");
	return 0;
}