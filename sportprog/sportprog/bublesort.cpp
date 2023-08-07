#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, sum=0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1 - j;i++) {
			if (a[i] > a[i + 1]) {
				int k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}