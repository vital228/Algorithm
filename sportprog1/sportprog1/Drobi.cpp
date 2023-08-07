#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int gcdex(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int x1, y1, g;
	g = gcdex(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}


int main() {
	int n,k,t;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int g;
			if ((g=gcd(n / i - 1, i)) > 1) {
				cout << "YES\n";
				cout << 2 << '\n';
				cout << i - 1 << " " << i << '\n';
				cout << (n / i - 1) / g << " " << n / g << '\n';
				return 0;
			}
			else {
				int a, b;
				g = gcdex(n / i, i, a, b);
				if ((n / i - 1) % g == 0) {
					a *= (n / i - 1) / g;
					b *= (n / i - 1) / g;

				}
			}
		}
	}
	cout << "NO";
}