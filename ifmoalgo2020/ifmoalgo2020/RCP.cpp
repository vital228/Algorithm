#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

const long long INF = 1000 * 1000 * 2001;

vector<int> d;

struct edge {
	int from;
	int to;
	int c;
	int f;
};
vector<edge> edges;
int s, t;
int dfs1(vector<vector<int>>& g, int v, int flow) {
	d[v] = 1;
	if (!flow) return 0;
	if (t == v) return flow;
	for (int i = 0; i < g[v].size(); i++) {
		edge e = edges[g[v][i]];
		int u = e.to;
		int add = 0;
		if (!d[u] && e.c > e.f) {
			add = dfs1(g, u, min(flow, e.c - e.f));
		}
		if (add) {
			edges[g[v][i]].f += add;
			edges[g[v][i] ^ 1].f -= add;
			return add;
		}
	}
	return 0;
}

long long flod(vector<vector<int>>& g) {
	long long flow = 0;
	d.assign(g.size(), 0);
	while (int add = dfs1(g, s, LONG_MAX)) {
		flow += add;
		d.assign(g.size(), 0);
	}
	return flow;
}


int main() {
	int a[6];
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	vector<vector<int>> gr(8);
	for (int i = 1; i < 4; i++) {
		for (int j = 4; j < 7; j++) {
			if ((i)%3+4 != j) {
				edges.push_back({i,j,(int)pow(10,8)+1,0});
				gr[i].push_back(edges.size() - 1);
				edges.push_back({ j,i,0, 0 });
				gr[j].push_back(edges.size() - 1);
			}
		}
	}
	for (int i = 1; i < 4; i++) {
				edges.push_back({ 0,i,a[i-1],0 });
				gr[0].push_back(edges.size() - 1);
				edges.push_back({ i,0,0, 0 });
				gr[i].push_back(edges.size() - 1);
	}
	for (int i = 4; i < 7; i++) {
		edges.push_back({ i,7,a[i - 1],0 });
		gr[i].push_back(edges.size() - 1);
		edges.push_back({ 7,i,0, 0 });
		gr[7].push_back(edges.size() - 1);
	}
	s = 0;
	t = 7;
	
	int x = -1;
	long long f = flod(gr);
	
	f = a[0] + a[1] + a[2] - f;
	cout << f;
	return 0;
}