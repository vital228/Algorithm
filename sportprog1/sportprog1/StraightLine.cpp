#include <iostream>
#include<vector>
#include<map>

using namespace std;

long long gcd(long long a, long long b, long long& x, long long& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long x, y;
	long long d = gcd(a, b, x, y);
	if (c % d == 0) {
		x *= -c / d;
		y *= -c / d;
		cout << x << " " << y;
	}
	else {
		cout << -1;
	}
	return 0;
}
	