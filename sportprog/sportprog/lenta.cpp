#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
 	vector<int> lent(n + 1, -1);
	lent[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i - a >= 0 && lent[i - a] != -1 && lent[i]< lent[i - a]+1) {
			lent[i] = lent[i - a] + 1;
		}
		if (i - b >= 0 && lent[i - b] != -1 && lent[i] < lent[i - b] + 1) {
			lent[i] = lent[i - b] + 1;
		}
		if (i - c >= 0 && lent[i - c] != -1 && lent[i] < lent[i - c] + 1) {
			lent[i] = lent[i - c] + 1;
		}
	}
	cout << lent[n];
	return 0;
}