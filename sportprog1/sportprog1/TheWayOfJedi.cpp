#include <iostream>
#include <vector>

using namespace std;


long long grd(long long a, long long b) {
	if (b == 0)
		return a;
	return grd(b, a % b);
}

long long phi(long long n) {
	long long ans = n;
	for (int i = 2;(long long) i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans -= ans / i;
		}
	}
	if (n > 1) {
		ans -= ans / n;
	}
	return ans;
}

long long binpow(long long a, long long n, long long m) {
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
	long long a, n;
	cin >> a;
	n = a;
	vector <int> ans;
	for (int i = 2;(long long) i * i <= n; i++) {
		if (a % i == 0) {
			ans.push_back(i);
			while (a % i == 0) {
				a /= i;
			}
		}
	}
	if (ans.size() > 1) {
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); ++i) {
			cout << 1 << " " << ans[i] << '\n';
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}