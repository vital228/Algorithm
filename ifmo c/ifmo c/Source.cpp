#include <iostream>
#include<algorithm>

using namespace std;

int main() {
	float a1 = 8.75, ax = 2.4, a2 = 1.56;
	int sum2 = 200;
	float maxi = 0;
	for (int i = 1; i <= 1000; i++) {
			if (sum2*a2 >= sum2 + i && i*ax >= sum2 + i  && maxi<(i * ax - sum2 + i) *(sum2 * a2 - sum2 + i)) {
				cout << i << ' ' << sum2 * a2 - i - sum2 << ' ' << i * ax - sum2 - i << '\n';
				maxi = (i * ax- sum2 + i) *( sum2 * a2- sum2 + i);
			}
	}
	cin >> a1;
}