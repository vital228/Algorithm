#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string a, b, ans = "";
	int sum = 0;
	int n;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		bool f = false;
		while (a[i] != b[i]) {
			f = true;
			i++;
		}
		if (f)
			sum++;
	}
	cout << sum;
	return 0;
}