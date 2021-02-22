#include <iostream>
#include "complex.h"
#include "complex_poly.h"

//DSL = Domain Specific Language
int main()
{
	Complex c(3, 4);
	c.print();
	c.conj().print();
	std::cout << "abs = " << c.abs() << '\n';

	Complex* dyn_c = new Complex();
	std::cout << (*dyn_c).real() << '\n';
	std::cout << dyn_c->real() << '\n';
	delete dyn_c;

	Complex a = sum(c, c.conj());
	std::cout << "sum = ";
	a.print();

	Complex b = c.sum(c.conj());

	Complex d = a + c;

	std::cout << (a / c) << '\n';

	Complex in_c;
	std::cin >> in_c;
	std::cout << "input: " << (double)in_c << '\n';

	std::cout << sqrt((double)in_c) << '\n';

	//1+2 <=> operator+(1, 2);
	//m[1][2] = (m[1])[2]

	ComplexPoly poly(3); //z^2+2*z+1 = (z+1)^2
	poly[0] = 1;
	poly[1] = 2;
	poly[2] = 1;

	std::cout << "poly(1) = " << poly(Complex(1)) << std::endl;

    return 0;
}