#include "Polynomial.h"

int Polynomial::maxDegree = 0;

void Polynomial::operator=(const Polynomial& polynomial) {
    this->actualDegree = polynomial.actualDegree;
    this->potentialDegree = polynomial.potentialDegree;
    this->coefficients = new double[potentialDegree+1];
    for (int i = 0; i <= potentialDegree;i++) 
            this->coefficients[i] = polynomial.coefficients[i];
}

Polynomial::Polynomial()
{
    this->potentialDegree = 0;
    this->actualDegree = 0;
    this->coefficients = new double[1];
    this->coefficients[0] = 0;
}

Polynomial::Polynomial(int degree)
{
    this->potentialDegree = degree;
    this->actualDegree = 0;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i < degree + 1; i++)
        this->coefficients[i] = 0;
}

Polynomial::Polynomial(double* coefficients, int degree)
{
    this->actualDegree = 0;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        this->coefficients[i] = coefficients[i];
        if (coefficients[i])
            actualDegree = i;
        if (coefficients[i] && i > maxDegree) {
            maxDegree = i;
        }
    }
    this->potentialDegree = degree;
}

Polynomial::~Polynomial()
{
    delete[] coefficients;
}

void Polynomial::setCoeff(int position, double coefficient)
{
    this->coefficients[position] = coefficient;
    if (position > maxDegree && coefficient)
        maxDegree = position;
}

int Polynomial::getDegree(bool flag) const
{
    if (!flag) {
        return potentialDegree;
    }
    for (int i = potentialDegree; i >= 0; i--) {
        if (this->coefficients[i] > 0)
            return i;
    }
    return 0;
}

int Polynomial::getMaxDegree()
{
    return maxDegree;
}

double Polynomial::getCoeff(int position) const
{
    return this->coefficients[position];
}

void Polynomial::print() const
{
    int monomPrints = 0;
    cout << "Polynomial = ";
    if (!potentialDegree||!actualDegree)
        cout << coefficients[0];
    else {
        for (int i = 0; i <= actualDegree; i++) {
            if (!i) {
                if (coefficients[i]) {
                    cout << coefficients[i];
                    monomPrints++;
                }
                else {
                    cout << 0;
                    monomPrints++;
                }
            }
            else if (coefficients[i] > 0 && monomPrints) {
                cout << "+" << coefficients[i] << "X^" << i;
                monomPrints++;
            }
            else {
                cout << coefficients[i] << "X^" << i;
                monomPrints++;
            }
        }
        if (!monomPrints)
            cout << 0;
    }
    cout << endl;
}