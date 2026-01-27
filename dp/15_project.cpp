#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;   // safety

    vector<int> a(n), b(n);
    vector<ll> c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // indices sorted by b
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;

    sort(order.begin(), order.end(), [&](int i, int j) {
        return b[i] < b[j];
    });

    vector<int> ends(n);
    for (int i = 0; i < n; i++)
        ends[i] = b[order[i]];

    vector<ll> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        // skip
        dp[i] = dp[i - 1];

        int idx = order[i - 1];
        int start = a[idx];

        // find first end >= start
        int pos = lower_bound(ends.begin(), ends.end(), start) - ends.begin();

        dp[i] = max(dp[i], dp[pos] + c[idx]);
    }

    cout << dp[n] << '\n';
    return 0;
}
