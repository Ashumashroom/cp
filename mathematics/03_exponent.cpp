#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// Fast exponentiation: a^b % mod
long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long c, x, y;
        cin >> c >> x >> y;

        // Step 1: compute (x^y) % (MOD - 1)
        // because of Fermat’s Little Theorem
        long long exp = modpow(x, y, MOD - 1);

        // Step 2: compute c^exp % MOD
        long long ans = modpow(c, exp, MOD);

        cout << ans << "\n";
    }
}
