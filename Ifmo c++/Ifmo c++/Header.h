#pragma once
#ifndef HEADER_H
#define HEADER_H
struct complexnumber {
	float a, b;
};
void swap(float* a, float *b);

void swap(float &a, float &b);

void mod(float &a);
void mod(float *a);
void multiplyComplexAndReal(complexnumber *a, float b);
void multiplyComplexAndReal(complexnumber &a, float b);
struct triangle {
	float x1, x2, x3, y1, y2, y3;
};
void Create_triangle(triangle &a, float x1, float y1, float x2, float y2, float x3, float y3);
float Square(triangle a);
bool operator ==(triangle &a, triangle &b);
bool operator >(triangle &a, triangle &b);
bool operator <(triangle &a, triangle &b);
bool operator !=(triangle &a, triangle &b);
struct fifo {
	int arr[100];
	int first = 0, last = 0;
};
fifo operator <<(fifo &a, int b);
fifo operator >>(fifo &a, int &b);
void fifoOUT(fifo a);
#endif // !HEADER_H
