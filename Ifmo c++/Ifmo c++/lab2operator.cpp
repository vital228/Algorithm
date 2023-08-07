#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	triangle a, b;
	float x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Create_triangle(a, x1, y1, x2, y2, x3, y3);
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Create_triangle(b, x1, y1, x2, y2, x3, y3);
	bool c= a == b;
	cout << c;
	c = operator==(a, b);
	cout << c;
	c = a > b;
	cout << c;
	c = operator>(a, b);
	cout << c;
	fifo q;
	int n;
	cin >> n;
	q << n;
	fifoOUT(q);
	n = 2;
	q >> n;
	fifoOUT(q);
	cout << n;
	system("pause");
	return 0;
}