#include<iostream>
using namespace std;
int main() {
	long long n;
	long long a, b;
	cin >> n;
	a = (n - 1) / 6 + (6 - (n - 1) % 6);
	b = n * 6;
	cout << a << " " << b;
	return 0;
}