#pragma once
#include <exception>
#include "complex.h"

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
	ComplexPoly(size_t const kSize) :	_size(kSize),
										_coeffs(new Complex[_size])
	{}

	ComplexPoly(size_t const kSize, Complex* coeffs)
	{
		initFromArray(kSize, coeffs);
	}

	// RULE OF THREE:
	// 1) Copy constructor
	ComplexPoly(ComplexPoly const& source) : ComplexPoly(source._size, source._coeffs) {}

	// 2) Assignment operator
	ComplexPoly& operator=(ComplexPoly const& source)
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

	Complex& operator[](int idx) const;
	Complex operator()(Complex const& val) const;
};