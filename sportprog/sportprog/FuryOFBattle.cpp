#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n, p, q;
	cin >> n >> p >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = 0;
	sort(a.begin(), a.end());
	int L = 0, R = a[n - 1] / q + min(a[n-1] % q, 1) + 1, M = (L + R) / 2;
	int ans = R - 1;
	while (L < R - 1) {
		M = (L + R) / 2;
		int needbig = 0;
		bool f = false;
		for (int i = 0; i < n; i++) {		
			int k = max(a[i] - M * q,0);
			if (p != q)
				needbig += k / (p - q) + min(k % (p - q), 1);
			else
				if (k > 0) {
					f = true;
				}
		}
		if (needbig <= M && !f) {
			R = M;
			ans = M;
		}
		else {
			L = M;
		}
	}
	cout << ans;
	return 0;
}