#include<bits/stdc++.h>
#define s e[i].second
using namespace std;
string d;
int x, p, N, i;
int main()
{
	cin >> N >> N >> N >> x >> p >> N >> N >> N;
	pair<int, int>e[16];
	e[N] = { x,p };
	for (; i < N; i++)cin >> e[i].first >> s;
	sort(e, e + N);
	for (;;)cin >> i >> p >> d, printf((p ^ s && (p < s) ^ (d[0] > 81)) ? "BLOCK\n" : "WAIT\n");
}