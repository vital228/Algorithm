#include <iostream>
#include <vector>

using namespace std;

int opr(vector<vector<int>>a, int n) {
	int sum = 0;
	if (n == 1) return a[0][0];
	for (int i = 0; i < n; i++) {
		vector<vector<int>> b = a;
		for (int j = 0; j < i; j++) {
			for (int k = 1; k < n; k++) {
				b[j][k - 1] = b[j][k];
			}
		}
		for (int j = i + 1; j < n; j++) {
			for (int k = 1; k < n; k++) {
				b[j - 1][k - 1] = b[j][k];
			}
		}
		for (int j = 0; j < n; j++) b[j].pop_back();
		b.pop_back();
		if (a[i][0] != 0) {
			if (i % 2 == 0) {
				sum += a[i][0] * opr(b, n - 1);
			}
			else {
				sum += -a[i][0] * opr(b, n - 1);
			}
		}
	}
	return sum;
}


int main() {
	int n;
	cin >> n;
	vector <vector<int>> a;

	for (int i = 0; i < n; i++) {
		vector <int> p;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			p.push_back(k);
		}
		a.push_back(p);
	}
	int k = opr(a, n);
	cout << k;
	int p;
	cin >> p;
	return 0;
}