#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string a, b, c,ans="";
	int n;
	cin>> n >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] == c[i] || (a[i] != b[i] && b[i] != c[i] && a[i] != c[i])) {
			ans += a[i];
		}
		else {
			if (a[i] == b[i] || a[i] == c[i]) {
				ans += a[i];
			}
			else
				ans += b[i];
		}
	}
	cout << ans;
	return 0;
}