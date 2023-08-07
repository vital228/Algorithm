#include <iostream>
#include <vector>

using namespace std;

long long inf = 1000000007;

int binpow(int a, int n, int m) {
	if (n == 0) {
		return (1 % m);
	}
	if (n & 1) {
		return (a * binpow(a, n - 1, m) % m);
	}
	long long t = binpow(a, n / 2, m);
	return ((t * t) % m);
}

int main() {
	int p;
	int sum = 0;
	cin >> p;
	for (int i = 1; i < p; i++) {
		bool f=true;
		for (int j = 1; j < p - 1; j++) {
			if (binpow(i, j, p) - 1 == 0) f = false;
		}
		int k = binpow(i, p - 1, p) - 1;
		if (k == 0 && f) sum++;
	}
	cout << sum;
	return 0;
}