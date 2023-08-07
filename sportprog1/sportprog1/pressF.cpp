#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void resh(int n, vector<int>& p) {
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!f[i]) {
            p.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i) {
                f[j] = 1;
            }
        }
    }
}


int main() {
    int l,r;
    cin >> l >> r;
    vector<int> p;
    resh(3500, p);
    int summ = 0;
    vector<int> f(r-l+1,0);
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < p.size(); j++) {
            if (i % (p[j] * p[j]) == 0) {
                f[i-l] = 1;
            }
        }
    }
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (gcd(i, j) == 1 && f[i-l]==0 && f[j-l]==0) {
                summ++;
            }
        }
    }
    cout << summ;
    return 0;
}