#include "Square_polynomial.h"

#include<iostream>
#include<stdio.h>

Square_polynomial::Square_polynomial(double A,double B,double C):a(A),b(B),c(C){
}
double Square_polynomial::value(double x) {
	return a * x*x + b * x + c;
}
int Square_polynomial::count_root() {
	if (b*b - 4 * a*c > 0) return 2;
	if (b*b - 4 * a*c == 0) return 1;
	return 0;
}
std::pair<double, double> Square_polynomial::roots() {
	std::pair <double, double> Roots;
	if(count_root() == 2) {
		Roots.first = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
		Roots.second= (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
		return Roots;
	}
	if (count_root() == 1) {
		Roots.first = -b / (2 * a);
		Roots.second = NULL;
		return Roots;
	}
	return Roots;
}
double Square_polynomial::max_or_min() {
	double x = -b / (2 * a);
	double y = a * x*x + b * x + c;
	return y;
}
void const Square_polynomial :: out() {
	printf("%lfx^2", a);
	if (b > 0)
		printf("+%lfx", b);
	if (b < 0)
		printf("%lfx", b);
	if (c > 0)
		printf("+%lf", c);
	if (c < 0)
		printf("%lf", c);
}