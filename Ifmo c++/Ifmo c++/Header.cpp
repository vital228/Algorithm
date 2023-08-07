#include <math.h>
#include <iostream>
#include "Header.h"
using namespace std;

void swap(float* a, float* b) {
	float k = *a;
	*a = *b;
	*b = k;
}
void swap(float &a, float &b) {
	float k = a;
	a = b;
	b = k;
}
void mod(float *a) {
	float k = *a;
	k = floor(k);
	*a = k;
}
void mod(float &a) {
	int k = a;
	a = k;
}
void multiplyComplexAndReal(complexnumber *a, float b) {
	complexnumber k = *a;
	k.a *= b;
	k.b *= b;
	*a = k;
}
void multiplyComplexAndReal(complexnumber &a, float b) {
	a.a *= b;
	a.b *= b;
}
void Create_triangle(triangle &a, float x1, float y1, float x2, float y2, float x3, float y3) {
	a.x1 = x1;
	a.x2 = x2;
	a.x3 = x3;
	a.y1 = y1;
	a.y2 = y2;
	a.y3 = y3;
}
float Square(triangle a) {
	return 0.5*sqrt(pow((a.x2 - a.x1)*(a.y3 - a.y2) - (a.y2 - a.y1)*(a.x3 - a.x2), 2));
}
bool operator ==(triangle &a, triangle &b) {
	if (Square(a) == Square(b))
		return true;
	else
		return false;
}
bool operator >(triangle &a, triangle &b) {
	if (Square(a) > Square(b))
		return true;
	else
		return false;
}
bool operator <(triangle &a, triangle &b) {
	if (Square(a) < Square(b))
		return true;
	else
		return false;
}
bool operator !=(triangle &a, triangle &b) {
	if (Square(a) != Square(b))
		return true;
	else
		return false;
}
fifo operator <<(fifo &a, int b) {
	a.arr[a.last] = b;
	a.last++;
	a.last %= 100;
	return a;
}
fifo operator >>(fifo &a, int &b) {
	b = a.arr[a.first];
	a.first++;
	a.first %= 100;
	return a;
}
void fifoOUT(fifo a) {
	int i = a.first;
	while (i != a.last) {
		cout << a.arr[i] << " ";
		i = (i + 1) % 100;
	}
	cout << endl;
}