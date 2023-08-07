#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>

using namespace std;

int main() {
	int n, m;
	n = 15000;
	cin >> m;
	vector<int> a(n + 1);
	for (int i = 0; i < m; i++) {
		int l, r,c;
		c = 1;
		cin >> l >> r;
		a[l - 1] += c;
		a[r] -= c;
	}
	int ans=0;
	int sum=0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
		if (ans > 0) {
			sum++;
		}	
	}
	cout << sum - 1;
	return 0;
}