#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
long long sum = 0;

void gen(vector<vector<int>>& p, vector<int>& flag, int n, int k) {
	if (k == n) {
		sum++;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!flag[i] && p[i][k]>0) {
				flag[i] = 1;
				gen(p, flag, n, k + 1);
				flag[i] = 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1);
	
	vector<int> flag(n+1, 0);
	for (int i = 0; i <= n; i++) {
		a[i].resize(n + 1);
		for (int j = 0; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//iota(p.begin(),p.end(),1);
	gen(a, flag, n+1, 0);
	cout << sum;
	//next_permutation(p.begin(),p.end());//bool

}