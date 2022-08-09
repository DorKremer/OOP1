#pragma once
#include "Polynomial.h"
class Rational
{
public:
	Rational();
	Rational(const Polynomial& nom, const Polynomial& denom);
	Polynomial& getNom();
	Polynomial& getDenom();
	void print() const;
	
private:
	Polynomial num, denom;
};

