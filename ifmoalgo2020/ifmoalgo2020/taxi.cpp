#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> graph[600];

bool parsoch(int k, vector<bool>& used, vector<int>& p2, vector<int>& p1) {
	if (used[k]) return false;
	used[k] = true;
	for (int u : graph[k]) {
		if (p2[u] == -1 || parsoch(p2[u], used, p2, p1)) {
			p2[u] = k;
			p1[k] = u;
			return true;
		}
	}
	return false;
}

struct ufo {
	int h, m;
	int x, y;
};

int subTime(ufo t1, ufo t2) {
	int t=0;
	if (t2.h < t1.h) {
		if (t2.m < t1.m) {
			t = (23 - t2.h + t1.h) * 60 + (60 - t1.m + t2.m);
		}
		else {
			t = (24 - t2.h + t1.h) * 60 + (t2.m - t1.m);
		}
	}
	else {
		if (t2.m < t1.m) {
			t = (t2.h - t1.h - 1) * 60 + (60 - t1.m + t2.m);
		}
		else {
			t = (t2.h - t1.h) * 60 + (t2.m - t1.m);
		}
	}

	return t;
}
double distance(double a, double b, double c, double d) {
	return (a - c)* (a - c) + (d - b)* (d - b);
}
bool cmd(const ufo a, const ufo b) {
	if (a.h != b.h) {
		return a.h < b.h;
	}
	if (a.m != b.m) {
		return a.m < b.m;
	}
	if (a.x != b.x) {
		return a.x <= b.x;
	}
	return a.y < b.y;
}
int main() {
	ifstream fin("ufo.in");
	ofstream fout("ufo.out");

	long long m,v;
	fin >> m >>v;
	vector<ufo> t(m);
	for (int i = 0; i < m; i++) {
		string s;
		fin >> s >> t[i].x >> t[i].y;
		int j = 0;
		t[i].h = (s[0]-'0') * 10 + (s[1] - '0');
		t[i].m = (s[3] - '0') * 10 + (s[4] - '0');
	}
	sort(t.begin(), t.end(), cmd);
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			if (v * subTime(t[i], t[j]) >= sqrt(distance(t[i].x, t[i].y, t[j].x, t[j].y)) * 60 && !(subTime(t[i], t[j]) == 0 && sqrt(distance(t[i].x, t[i].y, t[j].x, t[j].y))==0)) {
				graph[i].push_back(j);
			}
		}
	}
	vector<int> p2(m, -1);
	vector<int> p1(m, -1);
	for (int i = 0; i < m; i++) {
		vector <bool> used(m, false);
		parsoch(i, used, p2,p1);
	}
	vector <bool> used(m, false);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (!used[i]) {
			int j = i;
			used[j] = true;
			while (p1[j] != -1) {
				j = p1[j];
				used[j] = true;
			}
			sum++;
		}
	}
	fout << sum;
}
/*5
07:00 0 0 20 20
07:40 20 20 15 25
07:41 20 20 200 200
08:41 0 40 20 10
09:00 30 20 44 32*/