#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
vector <int> gr[100000];
bool used[100000];
int table[100000];
int c = 0;
bool f = true;
void dfs(int v, int p = -1, int t = 1) {
	used[v] = true;
	table[v] = t;
	for (int i = 0; i < gr[v].size(); i++) {
		int u = gr[v][i];
		if (u != p) {
			if (!(used[u]))
				dfs(u, v, -t);
			else
				if (table[v] == table[u])
					f = false;
		}
	}
}
int main() {
	int n, k;
	ifstream fin("bipartite.in");
	ofstream fout("bipartite.out");
	fin >> n >> k;
	for (int i = 0; i < k; i++) {
		int l, r;
		fin >> l >> r;
		gr[l - 1].push_back(r - 1);
		gr[r - 1].push_back(l - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i);
	}
	if (f) fout << "YES";
	else fout << "NO";
	return 0;
}