#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
vector<int> gr[100000];
int cl[100000];
vector<int> topsort;
vector <int> p;
int cycle_st,cycle_end;
bool dfs(int v) {
	cl[v] = 1;
	for (int i = 0; i < gr[v].size(); i++) {
		int u = gr[v][i];
		if (cl[u]==0) {
			p[u] = v;
			if (dfs(u)) return true;
		}
		else {
			if (cl[u] == 1) {
				cycle_st = u;
				cycle_end = v;
				return true;
			}
		}
	}
	cl[v] = 2;
	topsort.push_back(v);
	return false;
}


int main() {
	int n, k;
	ifstream fin("cycle.in ");
	ofstream fout("cycle.out");
	fin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		fin >> a >> b;
		gr[a - 1].push_back(b - 1);		
	}
	p.assign(n, -1);
	for (int i = 0; i < n; i++) {
		cl[i] = 0;
	}
	cycle_st = -1;
	for (int i = 0; i < n; i++) {
		if (cl[i]==0) {
			if (dfs(i))
				break;
		}
	}
	
	if (cycle_st==-1) {
		fout << "NO";
	}
	else {
		fout << "YES\n";
		vector <int> cycle;
		for (int v = cycle_end; v != cycle_st; v = p[v])
			cycle.push_back(v);
		cycle.push_back(cycle_st);
		for (int i = cycle.size() - 1; i >= 0; i--) {
			fout << cycle[i]+1 << " ";
		}

	}
	return 0;
}