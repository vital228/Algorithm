#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) {
	if (a == 0) {
		x = 0; y = 1;
		cout << a << b << x << y << '\n';
		return b;
	}
	long long x1, y1;
	long long d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	cout << a << " "<< b <<" "<< x <<" "<< y << '\n';
	return d;
}


int main() {
	long long a, b, n, m;
	cin >> a >> b;
	long long x, y;
	gcd(a, b, x, y);
	
	cout << gcd(a, b, x, y);

	
	return 0;
}