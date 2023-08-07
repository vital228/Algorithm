#include<iostream>
#include<vector>

using namespace std;
vector<int> graph[260];

bool parsoch(int k, vector<bool>& used, vector<int>& p2) {
	if (used[k]) return false;
	used[k] = true;
	for (int u : graph[k]) {
		if (p2[u] == -1) {
			p2[u] = k;		
			return true;
		}
		else {
			if (parsoch(p2[u], used, p2)) {
				p2[u] = k;
				return true;
			}
		}
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p2(260, -1);
	
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while (k!=0) {
			graph[i].push_back(k-1);
			cin >> k;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		vector<bool> used(n,false);
		if (parsoch(i, used, p2))
			sum++;

	}
	cout << sum<<'\n';
	for (int i = 0; i < m; i++) {
		if (p2[i] != -1) {
			cout << p2[i]+1<<  " " << i+1 << '\n';
		}
	}

	return 0;
}