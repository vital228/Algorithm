#include <iostream>
#include <fstream>
#include<vector>
#include<queue>
using namespace std;
vector<int> gr[100000];
queue<pair<int, int>> q;
int a[1000][1000];

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	fin >> n >> m;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			a[i][j] = -1;
		}
	}
	pair<int, int> f(0,0),s(0,0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a1;
			fin >> a1;
			if (a1 == '.')
				a[i][j] = 0;
			if (a1 == 'S') {
				q.push(make_pair(i, j));
				s = make_pair(i, j);
				a[i][j] = 0;
			}
			if (a1 == 'T') {
				f = make_pair(i, j);
				a[i][j] = 0;
			}
		}
	}
	if (f.first == 0 && f.second == 0) {
		fout << -1;
		return 0;
	}

	while (!q.empty()) {
		pair<int, int> v = q.front();
		if (a[v.first + 1][v.second] == 0) {
			a[v.first + 1][v.second] = a[v.first][v.second] + 1;
			q.push(make_pair(v.first + 1, v.second));
		}
		if (a[v.first][v.second + 1] == 0) {
			a[v.first][v.second + 1] = a[v.first][v.second] + 1;
			q.push(make_pair(v.first, v.second + 1));
		}
		if (a[v.first - 1][v.second] == 0) {
			a[v.first - 1][v.second] = a[v.first][v.second] + 1;
			q.push(make_pair(v.first - 1, v.second));
		}
		if (a[v.first][v.second - 1] == 0) {
			a[v.first][v.second - 1] = a[v.first][v.second] + 1;
			q.push(make_pair(v.first, v.second - 1));
		}
		q.pop();
	}
	a[s.first][s.second] = 0;
	if (a[f.first][f.second] > 0) {
		fout << a[f.first][f.second] << endl;
		int k = a[f.first][f.second];
		pair<int, int> v = f;
		vector<char> ans;
		while (k > 0) {

			if (a[v.first + 1][v.second] == k - 1) {
				v = make_pair(v.first + 1, v.second);
				ans.push_back('U');
			}
			else {
				if (a[v.first][v.second + 1] == k - 1) {
					v = make_pair(v.first, v.second + 1);
					ans.push_back('L');
				}
				else {
					if (a[v.first][v.second - 1] == k - 1) {
						v = make_pair(v.first, v.second - 1);
						ans.push_back('R');
					}
					else {
						v = make_pair(v.first - 1, v.second);
						ans.push_back('D');
					}
				}
			}
			k=a[v.first][v.second];
		}
		for (int i = ans.size()-1; i>=0; i--) {
			fout << ans[i];
		}
	}
	else {
		fout << -1;
	}

	return 0;
}