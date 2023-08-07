string str;
ll dp[100][100];
ll solve(ll l, ll r)
{
    ll res = 0;
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    if (r - l == 1 && l > r)
    {
        return dp[l][r] = 1;
    }
    if (str[l] != str[l + 1])
    {
        res += solve(l + 2, r);
    }
    if (str[r - 1] != str[r])
    {
        res += solve(l, r - 2);
    }
    if (str[l] != str[l + 1] && str[r - 1] != str[r])
    {
        res -= solve(l + 2, r - 2);
    }
    if (str[l] != str[r])
    {
        res += solve(l + 1, r - 1);
    }

    return dp[l][r] = res;
}

int main()
{
    FIO
        cin >> str;
    memset(dp, -1, sizeof dp);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == 'a')
            cnta++;
        else cntb++;
    }
    if (cnta != cntb && str.length() % 2)
    {
        cout << 0;
        return 0;
    }
    cout << solve(0, str.length() - 1) << '\n';
    return 0;
}