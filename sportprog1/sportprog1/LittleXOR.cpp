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
	unsigned long long n;
	cin >> n;
	vector<unsigned long long> a(n);
	vector <unsigned long long> prevx(n + 1);
	prevx[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prevx[i + 1] = prevx[i] ^ a[i];
	}
	unsigned long long ma = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			unsigned long long t = prevx[j + 1] ^ prevx[i];
			if (ma < t) {
				ma = t;
			}
		}
	}
	cout << ma;
}