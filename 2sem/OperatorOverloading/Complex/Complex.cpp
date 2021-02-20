#include <iostream>

class Complex
{
private:
    double _re;
    double _im;
public:
    Complex(double re = 0, double im = 0) : _re(re), _im(im) {}
    Complex(const Complex& src) : Complex(src._re, src._im) {}
	void print() const
	{
		std::cout << _re << "+(" << _im << ")i" << '\n';
	}

	double abs() const
	{
		return sqrt(_re * _re + _im * _im);
	}

	Complex conj() const
	{
		return Complex(_re, -_im);
	}

	double real() const { return _re; }
	double imag() const { return _im; }

	Complex sum(Complex const& right) const;
	//Complex operator+(Complex const& right) const
	//{
	//	return Complex(_re + right._re, _im + right._im);
	//}

	// WARNING!!! DANGER!!! USE WISELY!!! BETTER NOT TO USE AT ALL!!!
	friend Complex operator*(Complex const&, Complex const&);

	Complex operator*(double mult)
	{
		return Complex(_re * mult, _im * mult);
	}

	Complex operator/(double div) const
	{
		return (*this)*(1/div);
	}

	Complex& operator=(Complex const& right)
	{
		_re = right._re;
		_im = right._im;
		return *this;
	}

	Complex& operator+=(Complex const& right)
	{
		_re += right._re;
		_im += right._im;
		return *this;
	}

	Complex& operator++()
	{
		++_re;
		return *this;
	}

	Complex operator++(int)
	{
		Complex tmp = *this;
		++_re;
		return tmp;
	}

	operator double()
	{
		return _re;
	}
};

std::ostream& operator<<(std::ostream& out, Complex const& obj)
{
	return out << obj.real() << "+(" << obj.imag() << ")i";
}

std::istream& operator>>(std::istream& in, Complex& obj)
{
	double re, im;
	in >> re >> im;
	obj = Complex(re, im);
	return in;
}

Complex Complex::sum(Complex const& right) const
{
	return Complex(_re + right._re, _im + right._im);
}

Complex sum(Complex const& a, Complex const& b)
{
	return Complex(a.real() + b.real(), a.imag() + b.imag());
}

Complex operator+(Complex const& a, Complex const& b)
{
	return sum(a, b);
}

Complex operator*(Complex const& a, Complex const& b)
{
	return Complex(a._re*b._re -a._im*b._im, a._re *b._im + a._im *b._re);
}

Complex operator/(Complex const& a, Complex const& b)
{
	Complex const num = a * b.conj();
	double const b_abs = b.abs();
	double const den = b_abs*b_abs;
	return num / den;
}

bool operator>(Complex const& a, Complex const& b)
{
	return a.abs() > b.abs();
}

bool operator==(Complex const& a, Complex const& b)
{
	return !(a > b) && !(b > a);
}

bool operator<(Complex const& a, Complex const& b)
{
	return b > a;
}

bool operator>=(Complex const& a, Complex const& b)
{
	return !(a < b);
}

bool operator<=(Complex const& a, Complex const& b)
{
	return !(a > b);
}

bool operator!=(Complex const& a, Complex const& b)
{
	return !(a == b);
}

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

	//WARNING! implicit cast!
	std::cout << sqrt(in_c) << '\n';

	//1+2 <=> operator+(1, 2);

    return 0;
}