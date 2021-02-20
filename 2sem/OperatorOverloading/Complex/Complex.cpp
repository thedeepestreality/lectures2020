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

	Complex& operator*=(Complex const& right)
	{
		_re *= right._re;
		_im *= right._im;
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

	explicit operator double()
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

class ComplexPoly
{
private:
	size_t _size;
	Complex* _coeffs;
	void initFromArray(size_t const kSize, Complex* coeffs)
	{
		_size = kSize;
		for (size_t idx = 0; idx < _size; ++idx)
			_coeffs[idx] = coeffs[idx];
	}
public:
	ComplexPoly(size_t const kSize): _size(kSize),
									_coeffs(new Complex[_size])
	{}

	ComplexPoly(size_t const kSize, Complex* coeffs)
	{
		initFromArray(kSize, coeffs);
	}

	// RULE OF THREE:
	// 1) Copy constructor
	ComplexPoly(ComplexPoly& const source) : ComplexPoly(source._size, source._coeffs) {}

	// 2) Assignment operator
	ComplexPoly& operator=(ComplexPoly& const source)
	{
		if (_size)
			delete[] _coeffs;

		initFromArray(source._size, source._coeffs);
	}

	// 3) Destructor
	~ComplexPoly()
	{
		if (_size)
			delete[] _coeffs;
	}

	Complex& operator[](int idx) const
	{
		if (idx < 0 || idx >= _size)
			throw std::exception("index out of bounds");
		return _coeffs[idx];
	}

	Complex operator()(Complex const& val)
	{
		Complex sum;
		Complex deg(1);
		for (size_t idx = 0; idx < _size; ++idx)
		{
			sum += _coeffs[_size - idx - 1] * deg;
			deg *= val;
		}
		return sum;
	}
};

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

	//WARNING! implicit cast!
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