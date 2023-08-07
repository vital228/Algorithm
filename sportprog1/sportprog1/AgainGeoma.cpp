#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct point {
	double x;
	double y;
};


point peres(double a1, double b1, double c1, double a2, double b2, double c2) {
	double o = a1 * b2 - a2 * b1;
	double o1 = c1 * b2 - c2 * b1;
	double o2 = a1 * c2 - a2 * c1;
	point p;
	p.x = o1 / o;
	p.y = o2 / o;
	return p;
}

int main() {
	point p1, p2, p3;
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	point p4, p5;
	p4.x = (p1.x + p2.x) / 2;
	p4.y = (p1.y + p2.y) / 2;
	p5.x = (p3.x + p2.x) / 2;
	p5.y = (p3.y + p2.y) / 2;
	point v1, v2;
	v1.x = p2.x - p1.x;
	v1.y = p2.y - p1.y;
	v2.x = p2.x - p3.x;
	v2.y = p2.y - p3.y;
	double c1, c2;
	c1 = v1.x * p4.x + v1.y * p4.y;
	c2 = v2.x * p5.x + v2.y * p5.y;
	point o = peres(v1.x, v1.y, c1, v2.x, v2.y, c2);
	cout << sqrt((o.x - p1.x) * (o.x - p1.x) + (o.y - p1.y) * (o.y - p1.y));
	return 0;
}