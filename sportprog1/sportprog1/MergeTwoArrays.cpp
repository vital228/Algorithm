#include <iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int it1 = 0, it2 = 0;
	while (it1 < n && it2 < m) {
		if (a[it1] < b[it2]) {
			cout << a[it1] << " ";
			++it1;
		}
		else {
			cout << b[it2] << " ";
			++it2;
		}
	}
	while (it1 < n) {
		cout << a[it1] << " ";
		++it1;
	}
	while (it2 < m) {
		cout << b[it2] << " ";
		++it2;
	}
	return 0;
}