#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>

using namespace std;

int main() {
	long long n, s;
	cin >> n >> s;
	long long sum = 0;

	vector<long long> a(n);
	vector<long long> prev(n);
	map<long long, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0)
			prev[i] = prev[i - 1] + a[i];
		else
			prev[i] = a[i];
		if (m[prev[i]] == 0) {
			m[prev[i]] = 1;
		}
		else
			m[prev[i]]++;
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += m[s];
		m[prev[i]]--;
		s += a[i];
	}
	sum += m[s];
	cout << sum;
}
