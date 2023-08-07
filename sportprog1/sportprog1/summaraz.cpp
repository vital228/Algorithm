#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void gen(vector<int>& num, int sum, int n, int k) {
	if (sum==0) {
		for (int i = 0; i < k; i++) {
			if (i == 0) {
				cout << num[i];
			}
			else {
				cout << "+" << num[i];
			}
		}
		cout << endl;
		return;
	}
	else {
		for (int i = n; i > 0; i--) {
			num[k] = i;
			gen(num, sum - i, min(i,sum-i), k + 1);
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	vector<int> v(n+1);

	gen(v, n, n, 0);
	return 0;
}