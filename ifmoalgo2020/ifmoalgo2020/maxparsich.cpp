#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;


struct root {
	int index, w;
};

bool parsoch(int k, vector<bool>& used, vector<int>& p2, vector<int> graph[]) {
	if (used[k]) return false;
	used[k] = true;
	for (int u : graph[k]) {
		if (p2[u] == -1) {
			p2[u] = k;
			return true;
		}
		else {
			if (parsoch(p2[u], used, p2, graph)) {
				p2[u] = k;
				return true;
			}
		}
	}
	return false;
}
vector<root> v1, v2;
bool cmd(const root a, const root b) {
	return a.w > b.w;
}
int main() {
	int n, m, e;
	vector<int> graph[6000], rgraph[6000];
	vector<int> w1, w2;
	map<pair<int, int>, int> q;
	cin >> n >> m >> e;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		root b;
		b.index = i;
		b.w = a;
		w1.push_back(a);
		v1.push_back(b);
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		root b;
		b.index = i;
		b.w = a;
		w2.push_back(a);
		v2.push_back(b);
	}
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		rgraph[b - 1].push_back(a - 1);
		pair<int, int> p;
		p.first = a - 1;
		p.second = b - 1;
		q[p] = i + 1;
	}
	sort(v1.begin(), v1.end(), cmd);
	sort(v2.begin(), v2.end(), cmd);
	set<int> l, r;
	vector<int> p1(n,-1), p2(m,-1);

	for (int i = 0; i < n; i++) {
		vector<bool> used(n, false);
		if (parsoch(v1[i].index, used, p2, graph)) {
			l.insert(v1[i].index);
		}
	}
	for (int i = 0; i < m; i++) {
		vector<bool> used(m, false);
		if (parsoch(v2[i].index, used, p1, rgraph)) {
			r.insert(v2[i].index);
		}
	}
	vector<int> gr[6000];
	for (int i = 0; i < n; i++) {
		if (l.count(i)) {
			for (int j : graph[i]) {
				if (r.count(j)) {
					gr[i].push_back(j);
				}
			}
		}
	}
	vector<int> p(m,-1);
	int sum = 0;
	int w = 0;
	for (int i = 0; i < n; i++) {
		vector<bool> used(n, false);
		if (parsoch(i, used, p, gr)) {
			w += w1[i];
			sum++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (p[i] != -1) {
			w += w2[i];
		}
	}
	cout << w << '\n';
	cout << sum << '\n';
	for (int i = 0; i < m; i++) {
		if (p[i] != -1) {
			pair<int, int> pq;
			pq.first = p[i];
			pq.second = i;
			cout << q[pq] << " ";
		}
	}

	
}