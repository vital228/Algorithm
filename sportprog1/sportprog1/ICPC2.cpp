#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long sum = 0;
int gen(int n, int counter_open, int counter_close, string ans) {
    if (counter_open + counter_close == n) {
        bool f;
        for (int i = 0; i < n; i++) {
            if ( )
        }
        return 1;
    }
    if (counter_open < n / 2) {
        gen(n, counter_open + 1, counter_close, ans + '(');
    }
    if (counter_open > counter_close) {
        gen(n, counter_open, counter_close + 1, ans + ')');
    }
}