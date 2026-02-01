#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll dp[10][2][82];   // pos ≤ 9, sum ≤ 81
bool prime[82];

ll dfs(int pos, int tight, int sum)
{
    if (pos == (int)s.size())
        return prime[sum];

    ll &res = dp[pos][tight][sum];
    if (res != -1) return res;

    int up = tight ? (s[pos] - '0') : 9;
    res = 0;

    for (int d = 0; d <= up; d++)
        res += dfs(pos + 1, tight && (d == up), sum + d);

    return res;
}

ll countGOne(ll x)
{
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 1, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute primes up to 81
    memset(prime, false, sizeof(prime));
    for (int i = 2; i <= 81; i++)
    {
        bool ok = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0) ok = false;
        prime[i] = ok;
    }

    int c;
    cin >> c;
    while (c--)
    {
        ll f, t;
        cin >> f >> t;
        cout << countGOne(t) - countGOne(f - 1) << '\n';
    }
    return 0;
}