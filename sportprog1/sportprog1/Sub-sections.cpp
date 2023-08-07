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
	map<int, int> count;
	
	set<int, greater<int>> one;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (count[a[i]] == 0) {
			count[a[i]] = 1;
			one.insert(a[i]);
		}
		else {
			if (count[a[i]] == 1) {
				one.erase(a[i]);
				count[a[i]]++;
			}
			else
				count[a[i]]++;
		}
	}
	if (one.empty()) {
		cout << "Nothing" << endl;
	}
	else
		cout << *one.begin() << endl;
	for (int i = k; i < n; i++) {
		if (count[a[i-k]] == 1) {
			one.erase(a[i - k]);
		}
		else {
			if (count[a[i - k]] == 2) {
				one.insert(a[i - k]);
			}
		}
		count[a[i - k]]--;
		cin >> a[i];
		if (count[a[i]] == 0) {
			count[a[i]] = 1;
			one.insert(a[i]);
		}
		else {
			if (count[a[i]] == 1) {
				one.erase(a[i]);
				count[a[i]]++;
			}
			else
				count[a[i]]++;
		}
		if (one.empty()) {
			cout << "Nothing" << endl;
		}
		else
			cout << *one.begin() << endl;
	}
	return 0;
}