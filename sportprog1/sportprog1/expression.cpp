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


bool gen(vector<int>& num, vector<int>& sign, int sum, int n, int k, int m) {
	if (n-1==k) {
		if (sum == m) {
			cout << num[0];
			for (int i = 0; i < k; i++) {
				if (sign[i]) {
					cout << "+" << num[i+1];
				}
				else {
					cout << "-" << num[i+1];
				}
			}
			cout << "=" << m;
			return true;
		}

	}
	else {
		sign[k] = 1;
		bool f=gen(num, sign, sum + num[k + 1], n, k + 1, m);
		if (f)
			return true;
		sign[k] = 0;
		f=gen(num, sign, sum - num[k + 1], n, k + 1, m);
		return f;
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> sign(n - 1);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bool f=gen(v, sign, v[0], n, 0, m);
	if (!f) {
		cout << "No solution";
	}
	
	return 0;
}