#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



bool gen(vector<int>& sk, vector<int>& a1, vector<int>& a2, int& n, int k, int& plus1) {
	if (n == k) {
		return true;
	}
	else {
		if (sk[k] == a1[a1.size() - 1] + plus1) {
			a1.push_back(sk[k]);
			if (gen(sk, a1, a2, n, k + 1, plus1)) {
				return true;
			}
			a1.pop_back();
		}
		else {
			if (plus1 == 0) {
				plus1 = sk[k] - a1[0];
				a1.push_back(sk[k]);
				if (gen(sk, a1, a2, n, k + 1, plus1)) {
					return true;
				}
				plus1 = 0;
				a1.pop_back();
			}
		}
		if (a2.size() > 1) {
			int plus2 = a2[1] - a2[0];
			if (plus2 == plus1 && (a2[a2.size() - 1] - a1[0]) % plus1==0 && (a2[a2.size() - 2] - a1[0]) % plus1==0)
				return false;
			if (a2[a2.size() - 1] + plus2 == sk[k]) {
				a2.push_back(sk[k]);
				if (gen(sk, a1, a2, n, k + 1, plus1)) {
					return true;
				}
				a2.pop_back();
			}
		}
		else {
			a2.push_back(sk[k]);
			if (gen(sk, a1, a2, n, k + 1, plus1)) {
				return true;
			}
			a2.pop_back();
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> v(n);
	vector<int> a1;
	vector<int> a2;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	a1.push_back(v[0]);
	int plus = 0;
	if (gen(v, a1, a2, n, 1, plus)) {
		if (a2.size() == 0) {
			for (int i = 0; i < n - 1; i++) {
				cout << a1[i] << " ";
			}
			cout << "\n";
			cout << a1[n - 1];
		}
		else {
			for (int i = 0; i < a1.size(); i++) {
				cout << a1[i] << " ";
			}
			cout << "\n";
			for (int i = 0; i < a2.size(); i++) {
				cout << a2[i] << " ";
			}
		}
	}
	else {
		cout << "No solution";
	}

	return 0;
}