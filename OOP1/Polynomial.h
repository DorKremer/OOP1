#pragma once
#include <iostream>

using namespace std;
class Polynomial
{
public:
	Polynomial();
	Polynomial(int degree);
	Polynomial(double* coefficients, int degree);
	~Polynomial();
	void setCoeff(int position, double coefficient);
	int getDegree(bool flag) const;
	static int getMaxDegree();
	double getCoeff(int position) const;
	void print() const;
	void operator=(const Polynomial& polynomial);

private:
	int potentialDegree, actualDegree;
	double* coefficients;
	static int maxDegree;
};
