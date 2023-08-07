#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(100,0);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		a[k - 1]++;
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		sum += a[i] / 2;
	}
	cout << sum / 2;
	return 0;
}