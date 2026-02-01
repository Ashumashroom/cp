#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of testcases

    while (t--) {

        ll a;
        int n;
        cin >> a >> n;  // a = target sum, n = size

        read_vec(v, n);  // read vector

        unordered_map<ll, int> mp;  // prefix_sum -> first index
        ll sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i];

            // subarray starting from index 0
            if (sum == a) {
                ans = max(ans, i + 1);
            }

            // subarray ending at i
            if (mp.count(sum - a)) {
                ans = max(ans, i - mp[sum - a]);
            }

            // store first occurrence only
            if (!mp.count(sum)) {
                mp[sum] = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
