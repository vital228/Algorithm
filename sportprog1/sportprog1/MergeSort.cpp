#include <iostream>
#include<vector>

using namespace std;

void gen(vector<int>& a, int l,int r, int& k) {
	if (l + 1 >= r) {
		a[l] = a.size() - l;
		return;
	}
	if (k == 0) {
		int j = a.size() - r + 1;
		for (int i = l; i < r; i++) {
			a[i] = j;
			j++;
		}
		return;
	}
	if (k > 1) {
		k -= 2;
		gen(a, l, (r + l) / 2, k);
		gen(a, (r + l) / 2, r, k);
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	if (k%2==0 || (2*n-1)<k) {
		cout << "-1";
		return 0;
	}
	vector<int> a(n);
	k--;
	gen(a, 0, n, k);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}