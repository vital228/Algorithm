#pragma once
#include<iostream>
class Square_polynomial
{
	double a, b, c;
public:
	Square_polynomial(double A,double B,double C);
	double value(double x);
	int count_root();
	std::pair<double, double> roots();
	double max_or_min();
	void const out();
};

