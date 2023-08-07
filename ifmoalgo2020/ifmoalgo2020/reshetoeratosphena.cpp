#include<iostream>
#include<vector>


using namespace std;
const int MAX = 1000 * 1000;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> Mn[MAX + 1];
	Mn[1].push_back(1);
	for (int i = 2; i < 998; i++) {
		if (!Mn[i].size()) {
				int k = i*i;
				while (k <= MAX) {
					Mn[k].push_back(i);
					k += i;
				}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int k = a;
		for (int j = 0; j < Mn[a].size(); j++) {
			while (k % Mn[a][j] == 0) {
				cout << Mn[a][j] << " ";
				k /= Mn[a][j];
			}
		}
		if (!Mn[k].size()) {
			cout << k;
		}
		cout << '\n';
	}
	return 0;
}