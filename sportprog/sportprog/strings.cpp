#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	vector<string> s(2);
	s[0] = "A";
	s[1] = "AB";
	vector<long long> fib(60);
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < 60; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long m, n;
		cin >> m >> n;
		n--;
		if (m > fib[n]) {
			cout << "No solution\n";
			continue;
		}
		while (n > 1) {
			if (m > fib[n - 2]) {
				m = m - fib[n - 2];
				n--;
			}
			else {
				n -= 2;
			}
		}
		if (n == 1) {
			cout << s[1][m - 1] << '\n';
		}
		else {
			cout << "A\n";
		}


		/*for (int i = 2; i < n; i++) {
			string k = s[1];
			s[1] = s[0] + s[1];
			s[0] = k;
			cout << s[0] << '\n';
		}*/
	}
	return 0;
}