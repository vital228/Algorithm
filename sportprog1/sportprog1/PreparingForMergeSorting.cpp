#include <iostream>
#include<vector>

using namespace std;



int main() {
	int n;
	cin >> n ;
	vector<int> a(n);
	vector <vector<int>> ans;
	vector<int> last;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int l = -1, r = last.size();
		while (l < r - 1) {
			int m = (l + r) / 2;
			if (a[i] > last[m]) {
				r = m;
			}
			else {
				l = m;
			}
		}
		if (r == last.size()) {
			vector<int> b(1, a[i]);
			ans.push_back(b);
			last.push_back(a[i]);
		}
		else {
			last[r] = a[i];
			ans[r].push_back(a[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}