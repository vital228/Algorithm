#include<iostream>
#include<string>
#include<vector>

using namespace std;
void gen(vector<int> &num, int &n, int &m, int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << num[i]<<" ";
		}
		cout << endl;
		return;
	}
	else {
		for (int i = 0; i < m; i++) {
			num[k] = i + 1;
			gen(num, n, m, k + 1);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	gen(v, n, m, 0);
	return 0;
}