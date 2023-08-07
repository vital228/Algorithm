#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void gen(vector<int>& p, vector<int>& flag, int n, int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << p[i]<<" ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < flag.size(); i++) {
			if (!flag[i]) {
				p[k] = i + 1;
				flag[i] = 1;
				gen(p, flag, n, k + 1);
				flag[i] = 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n >> k;
	vector<int> flag(k,0);
	vector<int> p(n,0);
	//iota(p.begin(),p.end(),1);
	gen(flag, p, n, 0);
	
	//next_permutation(p.begin(),p.end());//bool
	
}
