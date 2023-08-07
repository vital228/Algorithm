#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
struct coin {
	int count;
	int num;
};

bool cmd(const coin a, const coin b) {
	return a.num > b.num;
}
vector<int> ans1(31);
int ansk = 31;

void gen(vector<coin>& num, vector<int>& ans, int sum, int m, int k) {
	if (sum == 0) {
		if (k < ansk) {
			ans1 = ans;
			ansk = k;
		}
	}
	else {
		for (int i = m; i < num.size(); i++) {
			if (num[i].count > 0 && sum>=num[i].num) {
				num[i].count--;
				ans[k] = num[i].num;
				gen(num, ans, sum - ans[k], i, k + 1);
				num[i].count++;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<coin> v(m);
	vector<int> ans(30,-1);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		coin k;
		cin >> k.num;
		k.count = 2;
		v.push_back(k);
		sum += 2 * k.num;
	}
	sort(v.begin(), v.end(), cmd);
	if (sum < n) {
		cout << -1;
		return 0;
	}
	gen(v, ans, n, 0, 0);
	if (ansk == 31) {
		cout << 0;
	}
	else {
		cout << ansk << endl;
		for (int i = 0; i < ansk; i++) {
			cout << ans1[i] << " ";
		}
	}
	return 0;
}