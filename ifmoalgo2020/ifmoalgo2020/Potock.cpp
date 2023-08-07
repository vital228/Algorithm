#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<map>
#include<list>
#include<queue>

using namespace std;

const long long INF = LLONG_MAX;

vector<long long> d;

struct edge {
	int from;
	int to;
	long long c;
	long long a;
	long long f;
	int reversed = -1;
	int id;
};
vector<edge> edges;
long long sum = 0;
int s, t;
int dfs1(vector<vector<int>>& g,int v,int flow) {
	d[v] = 1;
	if (!flow) return 0;
	if (t == v) return flow;
	for (int i = 0; i < g[v].size(); i++) {
		edge e = edges[g[v][i]];
		int u = e.to;
		int add = 0;
		if (!d[u] && e.c > e.f) {
//			add = dfs1(g, u, min(flow, e.c - e.f));
		}
		if (add) {
			edges[g[v][i]].f += add;
			sum += add * edges[g[v][i]].a;
			edges[g[v][i] ^ 1].f -= add;
			return add;
		}
	}
	return 0;
}

long long flod(vector<vector<int>>& g) {
	long long flow = 0;
	d.assign(g.size(), 0);
	while (int add=dfs1(g,s,LONG_MAX)) {
		flow+=add;
		d.assign(g.size(), 0);
	}
	return flow;
}


int main() {
	int n, m,k;
	cin >> n>>m>>k;
	vector<vector<int>> gr(n);
	s = 0;
	t = n - 1;
	vector<vector<edge>> edges(n+1,vector<edge>());
	edges[0].push_back({ 0,1,k,0,0 });
	edges[1].push_back({ 1,0,0,0,0 });
	edges[0].back().reversed = edges[1].size() - 1;
	edges[1].back().reversed = edges[0].size() - 1;
	vector<edge> v;
	for (int i = 0; i < m; i++) {
		edge e;
		pair < pair<int, int>, int> pa;
		cin >> e.from >> e.to >> e.a;
		e.f = 0;
		e.c = 1;
		e.id = i+1;
		edge rev = { e.to,e.from,1,e.a, 0 };
		rev.id = i + 1;
		edges[e.from].push_back(e);
		edges[e.to].push_back(rev);
		edges[e.from].back().reversed = edges[e.to].size() - 1;
		edges[e.to].back().reversed = edges[e.from].size() - 1;
		
	}
	long long f=0;
	bool found;
	//flod(gr);
	vector<int> id;
	vector<edge*> p;
	long long sum = 0;
	long long maxFlow = 0;
	while (true) {
		deque<int> q;
		id.assign(n + 1, 0);
		d.assign(n + 1, INF);
		p.resize(n + 1);

		d[0] = 0;
		q.push_back(0);

		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			id[u] = 2;

			for (edge& e : edges[u]) {
				
				if (e.f < e.c && d[e.to] > d[e.from] + e.a) {
					d[e.to] = d[e.from] + e.a;

					if (!id[e.to]) {
						q.push_back(e.to);
					}
					else if (id[e.to] == 2) {
						q.push_front(e.to);
					}

					id[e.to] = 1;
					p[e.to] = &e;
				}
			}
		}

		long long add = INF;

		if (d[n] == INF) {
			break;
		}
		else {
			for (int u = n; u != 0; u = p[u]->from) {
				edge* e = p[u];

				add = min(add, e->c - e->f);
			}

			for (int u = n; u != 0; u = p[u]->from) {
				edge* e = p[u];
				edge* reversed = &edges[e->to][e->reversed];

				e->f += add;
				reversed->f -= add;

				sum += add * e->a;
			}

			maxFlow += add;
		}
	}
	if (maxFlow == k) {
		//cout << sum / (double)k <<'\n';
		printf("%.5f\n", sum / (double)k);
		for (int j = 0; j < k; j++) {
			vector<int> path;
			for (int u = n; u != 1;) {
				for (edge& e : edges[u]) {
					if (e.f == -1) {
						edge* reversed = &edges[e.to][e.reversed];
						path.push_back(e.id);
						e.f += 1;
						reversed->f -= 1;
						u = e.to;
						break;
					}
				}
			}
			cout << path.size() << " ";
			for (int i = 0; i < path.size(); i++) {
				cout << path[path.size() - 1 - i] << " ";
			}
			cout << '\n';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}