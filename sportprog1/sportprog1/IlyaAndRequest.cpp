#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string s;
	vector<int> prev;
	cin >> s;
	int q;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			prev.push_back(0);
		}
		else {
			if (s[i] == s[i - 1]) {
				prev.push_back(prev[prev.size() - 1] + 1);
			}
			else {
				prev.push_back(prev[prev.size() - 1]);
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int f, l;
		cin >> f >> l;
		cout << prev[l - 1] - prev[f - 1] << endl;
	}
	return 0;
}
