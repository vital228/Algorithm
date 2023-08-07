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
	long long n;
	vector<long long> p;
	cin >> n;
	for (int i = 2; i * i < n; i++) {
		if (n % i==0) {
			p.push_back(i);
			p.push_back(n / i);
		}
	}
	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			if ((p[i] * p[j]) % n == 0) {
				long long k = p[i] * p[j] / n;
				long long a, c;
				long long d = gcd(p[i], p[j], a, c);
				if ((k * (n - 1)) % d == 0) {
					a *= k * (n - 1) / d;
					c *= k * (n - 1) / d;
					if (a < 0) {
						long long k = -a * d / p[j] + (((-a) * d) % p[j] > 0);
						a += k * p[j] / d;
						c -= k * p[i] / d;
					}
					else {
						if (c < 0) {
							long long k = -c * d / p[i] + (((-c) * d) % p[i] > 0);
							a -= k * p[j] / d;
							c += k * p[i] / d;
						}
					}
					cout << "YES\n";
					cout << "2\n";
					cout << a << " " << p[j] << "\n" << c << " " << p[i] << '\n';
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}