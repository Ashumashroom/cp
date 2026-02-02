#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 0001 consider t be worng the we use one more index that as it started or not 
ll dp[20][2][11][2];
string s;

ll fun(int index, bool tight, int prev, bool started) {
    if (index == s.size())
        return 1;

    ll &res = dp[index][tight][prev][started];
    if (res != -1) return res;
    res = 0;

    int ul = tight ? (s[index] - '0') : 9;

    for (int d = 0; d <= ul; d++) {
        bool nstarted = started || (d != 0);

        // check adjacency only after number has started
        if (started && nstarted && prev != 10 && d == prev)
            continue;

        int nprev = nstarted ? d : 10;
        bool ntight = tight && (d == ul);

        res += fun(index + 1, ntight, nprev, nstarted);
    }
    return res;
}

ll solve(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return fun(0, 1, 10, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << "\n";
    return 0;
}