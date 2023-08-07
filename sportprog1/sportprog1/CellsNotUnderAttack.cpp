#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>

using namespace std;

int main() {
	set<int> selsW;
	set<int> selsH;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int h, w;
		cin >> h >> w;
		selsH.insert(h);
		selsW.insert(w);
		cout << (long long)(n - selsW.size()) * (n - selsH.size())<<endl;
	}
	return 0;
}