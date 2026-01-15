#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; 
    int k;
    cin >> n >> k;

    vector<ll> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    ll ans = 0;

    for (int mask = 1; mask < (1 << k); mask++) {
        int cnt = __builtin_popcount(mask);
        __int128 res = 1; // prevent overflow

        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                res *= a[j];
                if (res > n) break; // avoid overflow and useless work
            }
        }

        if (res > n) continue;

        if (cnt % 2 == 1) ans += n / (long long)res;
        else ans -= n / (long long)res;
    }

    cout << ans << "\n";
    return 0;
}
