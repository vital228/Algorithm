#include<iostream>
#include<string>
#include<vector>

using namespace std;
typedef unsigned long long ll;

int main() {
	ll n, Mod;
	cin >> n >> Mod;
	//Mod *= 2;
	ll sum2 = 0;
	vector<ll> ch(n + 1);
	ll ans;
	ll sumd = 0;
	ch[0] = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ch[i + 1] = ch[i]+a[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	ans = 0;
	sumd = a[0];
	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			ans = (ans + ((ch[i + 1] - ch[j])*sumd&(Mod-1)))&(Mod-1);
			sumd = (sumd + (ch[i + 1] - ch[j])) & (Mod - 1);
		}
	}
	cout << ans;

	/*if (n > 2) {
		ll ans = (d[n - 2] * (d[n - 1] - 1+Mod) % Mod * sum1 * sum1 % Mod + d[n - 3] * (sum1 * sum1 - sum2 + Mod) % Mod) % Mod;
		cout << ans;
	}
	else {
		//Mod /= 2;
		ll ans = (sum1 * sum1 % Mod + a[0] * a[1] % Mod) % Mod;
		cout << ans;
	}*/
}