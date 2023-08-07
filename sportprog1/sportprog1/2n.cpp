#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	unsigned long long n, a,b,c;

	int t;
	cin >> t;

	for (int i = 0; i <t; i++) {
		cin >> a >> b >> n;
		c = a ^ b;
		if (n % 3 == 0) {
			cout << a;
		}
		if (n % 3 == 1) {
			cout << b;
		}
		if (n % 3 == 2) {
			cout << c;
		}
		cout << endl;
	}
	return 0;
}