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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i = 1;
	int k = ~i; //побитовое не
	i = i << 25;
	i--;
	i = i << 9;
	k = i ^ i;//xor побитовый
	cout << ~i;
	int n, t;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ans ^= t;
	}
	cout << ans;
	//a>b>c
	//a^c>min(a^b,b^c);
	//2 4 5 7 8 10

	return 0;
}