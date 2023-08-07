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
	int n, q;
	cin >> n;
	vector<int> a(n), prev(n + 1);
	prev[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		prev[i + 1] = prev[i] + a[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << prev[r] - prev[l-1]<<endl;
	}
	return 0;
}