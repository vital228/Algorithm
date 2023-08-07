#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long sum = n * (n + 1) / 2;
	if (n * (n + 1) % 4 == 0 && sum/2<=n) {
		cout << "1 " << n * (n + 1) / 4;
		return 0;
	}
	long long t,t10;
	for (long long i = 10; i < sum; i *= 10) {
		t = sum % (i + 1);
		t10 = t + i + 1;
		long long p;
		if (t % 2 == 0 && t / 2 < i && t / 2 >= i / 10 && t/2<=n) {
			p = (sum - t) / (i + 1);
			t /= 2;
			if (p > 0 && p <= n && p!=t) {
				cout << "2 " << p << " " << t;
				return 0;
			}
		}
		if (t10 % 2 == 0 && t10 / 2 < i && t10 / 2 >= i / 10 && t10/2<=n) {
			p = (sum - t10) / (i + 1);
			t10 /= 2;
			if (p > 0 && p<=n && p!=t10) {
				cout << "2 " << p << " " << t10;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}