#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<set>
#include<list>

using namespace std;
vector<bool> used;
vector<int> p2;
ifstream fin("birthday.in");
ofstream fout("birthday.out");
//ifstream fin("input.txt");
//ofstream fout("output.txt");
vector<vector<int>> graph;
bool parsoch(int k, vector<vector<int>> graph, int n, int m) {
	if (used[k]) return false;
	used[k] = true;
	for (int u : graph[k]) {
		if (p2[u] == -1 || parsoch(p2[u], graph, n, m)) {
			p2[u] = k;
			return true;
		}
	}
	return false;
}

void dfs(int k, vector<vector<int>> graph, vector<int>& l, vector<int>& r, int n, int m) {
	if (used[k]) return;
	l[k] = 1;
	for (int u : graph[k]) {
		if (r[u] != 0) {
			r[u] = 0;
			if (p2[u] != -1 && !used[p2[u]]) {
				dfs(p2[u], graph, l, r, n, m);
			}
		}
	}
}
void out(int n, int m) {
	fout << max(n, m) << '\n';
	fout << max(n, m) * (n > m) << " " << max(n, m) * (n <= m) << '\n';
	for (int i = 0; i < max(n, m) * (n > m); i++) {
		fout << i + 1 << " ";
	}
	fout << '\n';
	for (int i = 0; i < max(n, m) * (n <= m); i++) {
		fout << i + 1 << " ";
	}
	fout << "\n\n";
}
void getPeople(vector<vector<int>> graph, int n, int m) {
	p2.assign(m, -1);
	int sum = 0;
	vector<int> noParsoch;
	vector<int> lroot(n, 0);
	vector<int> rroot(m, 1);
	vector<bool> used1(n, false);
	for (int i = 0; i < n; ++i)
		for (int j : graph[i]) {
			if (p2[j] == -1) {
				p2[j] = i;
				used1[i] = true;
				sum++;
				break;
			}
		}
	for (int i = 0; i < n; i++) {
		if (used1[i]) continue;
		used.assign(n, false);
		if (parsoch(i, graph, n, m)) {
			sum++;
		}
		else {
			noParsoch.push_back(i);
		}
	}
	used.assign(n, false);
	for (int i = 0; i < noParsoch.size(); i++) {
		int v = noParsoch[i];
		dfs(v, graph, lroot, rroot, n, m);
	}
	int suml = 0;
	int sumr = 0;
	for (int i = 0; i < n; i++) {
		if (lroot[i] == 1) {
			suml++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (rroot[i] == 1) {
			sumr++;
		}
	}

	fout << suml + sumr << '\n';
	fout << suml << " " << sumr << '\n';
	for (int i = 0; i < lroot.size(); i++) {
		if (lroot[i] == 0) continue;
		fout << i + 1 << " ";
	}
	fout << '\n';
	for (int i = 0; i < rroot.size(); i++) {
		if (rroot[i] == 0) continue;
		fout << i + 1 << " ";
	}
	fout << "\n\n";
}
int main() {
	int k;
	ios_base::sync_with_stdio(false);
	fin >> k;
	vector<vector<int>> graph(150);
	for (int i = 0; i < 150; i++) {
		graph[i].assign(150, 1);
	}
	for (int q = 0; q < k; q++) {
		int n, m;
		fin >> n >> m;
		vector<vector<int>> gr(n);
		for (int j = 0; j < n; j++) {
			vector<int> v = graph[j];
			int l;
			fin >> l;
			while (l != 0) {
				l--;
				v[l] = 0;
				fin >> l;
			}
			for (int i = 0; i < m; i++) {
				if (v[i] == 1) {
					gr[j].push_back(i);
				}
			}
		}
		getPeople(gr, n, m);
	}
	return 0;
}