#include "Rational.h"

Rational::Rational()
{
    this->denom.setCoeff(0,1);
}

Rational::Rational(const Polynomial& nom, const Polynomial& denom)
{
    this->num = nom;
    this->denom = denom;
}

Polynomial& Rational::getNom()
{
    return this->num;
}

Polynomial& Rational::getDenom()
{
    return this->denom;
}

void Rational::print() const
{
    num.print();
    cout << "--------------------------\n";
    denom.print();
}


