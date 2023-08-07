#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;
set<int> ans;
int generator(set<int>& s, vector<unsigned long long>& a, unsigned long long sum, int k, int n, int m) {
	unsigned long long d = 1;
	d = d << (n)-1;
	if (d == sum) {
		return s.size();
	}
	for (int i = k; i < m; i++) {
		unsigned long long t = a[i] & sum;
		if (t != a[i]) {
			s.insert(i);
			t = sum | a[i];

			generator()
		}
	}

}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	vector<unsigned long long> a;
	unsigned long long t = 1;
	int n,m;
	cin >> n >> m;
	a.resize(m);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int b;
			cin >> b;
			a[i] += t << (b-1);
			t = 1;
		}
	}
}