#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;
vector<int> graph[20000];
vector<bool> used;
vector<int> p2;
bool parsoch(int k) {
	if (used[k]) return false;
	used[k] = true;
	for (int u : graph[k]) {
		if (p2[u] == -1 || parsoch(p2[u])) {
			p2[u] = k;
			return true;
		}		
	}
	return false;
}

int main() {
	ifstream fin("dominoes.in");
	ofstream fout("dominoes.out");
	int n, m, a, b;
	bool ground[501][501];
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			ground[i][j] = false;
		}
	}
	fin >> n >> m >> a >> b;
	int countfree = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			fin >> c;
			if (c == '*') {
				ground[i][j] = true;
				countfree++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!ground[i][j] || (i+j)%2==0) {
				continue;
			}
			if (i && ground[i - 1][j]) {
				graph[i * m + j].push_back((m * (i - 1) + j));
			}
			if (i < n - 1 && ground[i + 1][j]) {
				graph[i * m + j].push_back((m * (i + 1) + j));
			}
			if (j && ground[i][j - 1]) {
				graph[i * m + j].push_back((m * i + j - 1));
			}
			if (j < m - 1 && ground[i][j + 1]) {
				graph[i*m+j].push_back((m * i + j + 1));
			}
		}
	}
	if (2 * b <= a) {
		fout << countfree * b;
		return 0;
	}
	p2.assign((n+1)*(m+1), -1);
	int sum = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			used.assign((n+1) * (m+1), false);
			if ((i + j) % 2 == 0) continue;
			if (parsoch(i * m + j))
				sum++;
		}
	}
	fout << a * sum + (countfree - 2 * sum) * b;
	return 0;
}