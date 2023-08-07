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
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		if (m.size() == 1) {
			cout << i;
			return 0;
		}
		int x, t;
		cin >> x >> t;
		x--;
		m[a[x]]--;
		if (m[a[x]] == 0) {
			m.erase(a[x]);
		}
		a[x] = t;
		m[a[x]]++;
		
	}
	if (m.size() != 1) {
		cout << -1;
	}
	else {
		cout << k;
	}
	return 0;
}