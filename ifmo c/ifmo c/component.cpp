#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
vector<int> gr[200000], rgr[200000];
vector<bool> used;
int component[100000];
vector<int> topsort;
void dfs1(int v) {
	used[v] = true;
	for (int i = 0; i < gr[v].size(); i++) {
		int u = gr[v][i];
		if (!used[u])
			dfs1(u);
	}

	topsort.push_back(v);
}
void dfs2(int v, int c) {
	used[v] = true;
	component[v] = c;
	for (int i = 0; i < rgr[v].size(); i++) {
		int u = rgr[v][i];
		if (!used[u])
			dfs2(u, c);
	}
}


int main() {
	int n, k;
	ifstream fin("cond.in");
	ofstream fout("cond.out");
	fin >> n >> k;
	used.assign(n, false);
	for (int i = 0; i < k; i++) {
		int l, r;
		fin >> l >> r;
		gr[l - 1].push_back(r - 1);
		rgr[r - 1].push_back(l - 1);
	}

	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs1(i);
	}
	used.assign(n, false);
	int c = 1;
	for (int i = 0; i < n; ++i) {
		int v = topsort[n - 1 - i];
		if (!used[v]) {
			dfs2(v, c);
			c++;
		}
	}
	fout << c - 1 << endl;
	for (int i = 0; i < n; i++) {
		fout << component[i] << " ";
	}
	return 0;
}