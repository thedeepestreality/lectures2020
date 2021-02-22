#include "complex_poly.h"

Complex& ComplexPoly::operator[](int idx) const
{
	if (idx < 0 || idx >= _size)
		throw std::exception("index out of bounds");
	return _coeffs[idx];
}

Complex ComplexPoly::operator()(Complex const& val) const
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