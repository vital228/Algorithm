#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	priority_queue<int, vector<int>, greater<int>> p;
	p.push(a[0]);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 1) {
			p.push(a[i]);
		}
		else {
			p.push(a[i]);
			p.pop();
		}
	}
	long long k = 0;
	while (!p.empty()) {
		k += p.top();
		p.pop();
	}
	cout << k << " " << sum - k;
}