#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0] = a[0];
    if (s == "tail") {
        for (int i = 1; i < n; i++) {

        }
    }
    else {
        d[1] = max(d[0], a[1]);
        for (int i = 2; i < n; i++) {
            long long sum = 0;
            d[i] = a[i];
            for (int j = i - 2; j >= 0 && sum<a[j]; j--) {
                d[i] = max(d[i], d[j] + a[i]);
            }
            cout << d[i] << ' ';
        }

    }
    return 0;
}