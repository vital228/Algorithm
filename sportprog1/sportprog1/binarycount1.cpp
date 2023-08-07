#include<iostream>
#include<string>
#include<vector>

using namespace std;
void gen(vector<int>& num, int& n, int m, int count, int k) {
	if (k == n) {
		if (count == m) {
			for (int i = 0; i < n; i++) {
				cout << num[i];
			}
			cout << endl;
		}
		return;
	}
	else {
		if (n - k > m - count) {
			num[k] = 0;
			gen(num, n, m, count, k + 1);
		}
		if (count < m) {
			num[k] = 1;
			gen(num, n, m, count + 1, k + 1);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	gen(v, n, m, 0, 0);
	return 0;
}