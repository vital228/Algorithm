#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long mul(long long a, long long b, long long m) {
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (t + t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;
}

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
	long long c, e, n, m;
	cin >> n >> e >> c;
	long long p,q,qn;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			p = i;
			q = n / i;
			break;
		}
	}
	long long d, y;
	qn = (p - 1) * (q - 1);
	gcd(e, qn, d, y);
	p = -d / qn;
	d += p * qn;
	if (d < 0) {
		d += qn;
	}
	m = pows(c, d, n);
	cout << m;

	return 0;
}