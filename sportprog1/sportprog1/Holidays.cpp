#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000009;


long long mulmod(long long a, long long b, long long m) {
	if (b == 0) {
		return (0 % m);
	}
	if (b & 1) {
		return ((a + mulmod(a, b - 1, m)) % m);
	}
	long long t = mulmod(a, b / 2, m);
	return ((t + t) % m);
}

long long C(int n, int k, vector<long long>& fact, vector<long long>& invfact) {
	return mulmod(mulmod(fact[n],invfact[k],mod) , invfact[n - k] ,mod);
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
	int N;
	cin >> N;
	vector<long long> fact(N+1);
	vector<long long> inv(N+1);
	vector<long long> invfact(N+1);
	long long sum = 0;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}
	for (int i = 1; i < N; i++) {
		long long c = C(N, i, fact, invfact);
		long long c1 = binpow(2, N - i, mod) - 1;
		c = mulmod(c, c1, mod);
		sum = (sum + c)%mod;
	}
	cout << sum;
	return 0;
}