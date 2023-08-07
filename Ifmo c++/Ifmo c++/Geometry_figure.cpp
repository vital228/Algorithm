#include "Geometry_figure.h"
#include<iostream>
#include<math.h>
using namespace std;
const double pi = 3.1415926;

void Circle::initFromDialog() {
	cout << "Write coordinate centre of circle: ";
	cin >> c.x >> c.y;
	cout << "\nWrite radius circle: ";
	cin >> r;
	cout << "Write mass: ";
	cin >> m;
}
double Circle::square() {
	return pi * r*r;
}
double Circle::perimeter() {
	return 2 * pi*r;
}
double Circle::mass()const{
	return m;
}
CVector2D Circle::position() {
	return c;
}
bool Circle::operator==(const IPhysObject& ob)const {
	
	return mass() == ob.mass();
}
bool Circle::operator<(const IPhysObject& ob)const {
	return m < ob.mass();
}
void Circle::draw() {
	cout << "Square:" << square();
	cout << "\nPerimeter:" << perimeter();
	cout << "\nmass:" << mass();
	CVector2D t = position();
	cout << "\nPosition:" << t.x << " " << t.y<<endl;
}
const char* Circle::classname() {
	return "Circle";
}
unsigned int Circle::size() {
	return sizeof(classname());
}

void Rectange::initFromDialog() {
	cout << "Write coordinate 3 point of rectangle: ";
	cin >> x1 >> y1 >> x2 >> y2>> x3>> y3;
	cout << "Write mass: ";
	cin >> m;
}
double Rectange::square() {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
}
double Rectange::perimeter() {
	return 2 * (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))+sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3)));
}
double Rectange::mass() const{
	return m;
}
CVector2D Rectange::position() {
	CVector2D t;
	t.x = (x3+x1)/2;
	t.y = (y3+y1)/2;
	return t;
}
bool Rectange::operator==(const IPhysObject& ob)const {
	return m == ob.mass();
}
bool Rectange::operator<(const IPhysObject& ob)const {
	return m < ob.mass();
}
void Rectange::draw() {
	cout << "Square:" << square();
	cout << "\nPerimeter:" << perimeter();
	cout << "\nmass:" << mass();
	CVector2D t = position();
	cout << "\nPosition:" << t.x << " " << t.y<<endl;
}
const char* Rectange::classname() {
	return "Rectange";
}
unsigned int Rectange::size() {
	return sizeof(classname());
}