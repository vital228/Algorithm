#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	float a, b;
	cin >> a >> b;
	swap(&a, &b);
	cout << a <<" "<< b<<endl;
	swap(a, b);
	cout << a << " " << b;
	cin >> a;
	b = a;
	mod(&b);
	mod(a);
	cout << b << endl << a;
	complexnumber cnumber1,cnumber2;
	cin >> cnumber1.a >> cnumber1.b>>a;
	cnumber2 = cnumber1;
	multiplyComplexAndReal(&cnumber1, a);
	cout << cnumber1.a<< " " <<cnumber1.b<<endl;
	multiplyComplexAndReal(cnumber2, a);
	cout << cnumber2.a << " " << cnumber2.b;
	system("pause");
	return 0;
}