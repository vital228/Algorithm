#include<iostream>
#include<vector>
#include<math.h>
#include <time.h>


using namespace std;
const int MAX = 1000;
long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) return a + b;
	if (a > b)
		return gcd(a % b, b);
	return gcd(b % a, a);
}
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

bool isPrime(long long n) {
	if (n == 2 || n == 3)
		return true;
	if (n == 1 || n % 2 == 0)
		return false;
	long long s = 0;
	long long t = n - 1;
	while (t % 2 == 0) {
		t /= 2;
		s++;
	}
	for (int i = 0; i < 15; i++) {
		long long a = rand() % (n - 3) + 2;
		if (gcd(a, n) != 1) {
			return false;
		}
		a = pows(a, t, n);
		if (a == 1 || a == n - 1)
			continue;
		for (int j=1;j<s;j++){
			a = pows(a, 2, n);

			if (a == 1) {
				return false;
			}
			if (a == n - 1) {
				break;
			}
		}
		if (a != n - 1)
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<bool> prime(MAX+1,false);
	vector<long long> p;
	prime[1]=true;
	/*for (int i = 2; i*i <= MAX; i++) {
		if (!prime[i]) {
			int k = i * i;
			while (k <= MAX) {
				prime[k]=true;
				k += i;
			}
		}
		else {
			p.push_back(i);
		}
	}*/
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		/*if (a[i]<MAX && !prime[a[i]]) {
			cout<<"YES\n";
			continue;
		}
		bool f = false;
		for (int j = 0; j < p.size(); j++) {
			if (a[i] % p[j] == 0) {
				cout << "NO\n";
				f = true;
				break;
			}
		}
		if (f) {
			continue;
		}*/
		if (isPrime(a[i])) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}