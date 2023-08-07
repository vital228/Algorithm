#include <iostream>
#include<vector>

using namespace std;
vector<int> res;
long long sum = 0;
void merge(vector<int>& a, int l, int m, int r) {
	int it1 = 0, it2 = 0;
	while (l + it1 < m && m + it2 < r) {
		if (a[l + it1] > a[m + it2]) {
			res[it1 + it2] = a[m + it2];
			sum += m - it1 - l;
			it2++;
		}
		else {
			res[it1 + it2] = a[l + it1];
			it1++;
		}
	}
	while (l + it1 < m) {
		res[it1 + it2] = a[l + it1];
		it1++;
	}
	while (m + it2 < r) {
		res[it1 + it2] = a[m + it2];
		it2++;
	}
	for (int i = 0; i < r - l; i++) {
		a[l + i] = res[i];
	}
}

void sortsliyam(vector<int>& a, int l, int r) {
	if (r - l == 1) return;
	sortsliyam(a, l, (l + r) / 2);
	sortsliyam(a, (l + r) / 2, r);
	merge(a, l, (l + r) / 2, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	res.resize(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sortsliyam(a, 0, n);
	}
	cout << sum;

}