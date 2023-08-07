#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int main() {
	int n;
	string s1,s2;
	cin >> n;
	cin >> s1;
	cin >> s2;
	long long sum = 0;
	vector<int> a(4, 0);
	for (int i = 0; i < n; i++) {
		long long t = 0;
		for (int j = 0; j < 4; j++) {
			int o1 = j % 2, o2 = j/2;
			int c = ((o1 | o2) << 1) + ((s1[i] - 48) | (s2[i] - 48));
			int d = (((s1[i] - 48) | o2) << 1) + (o1 | (s2[i] - 48));
			if (c != d) {
				t += a[j];
			}
		}
		sum += t;
		a[((s2[i] - 48) << 1) + (s1[i] - 48)]++;
	}
	cout << sum;
	return 0;
}