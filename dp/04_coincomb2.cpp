#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: one way to make sum 0 — take no coins
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill table
    for (int i = n - 1; i >= 0; i--) {       // iterate coins backward
        for (int sum = 1; sum <= k; sum++) { // iterate over possible sums
            int take = 0;
            if (sum - coins[i] >= 0)
                take = dp[i][sum - coins[i]];  // reuse same coin
            int skip = dp[i + 1][sum];         // skip this coin
            dp[i][sum] = (take + skip) % MOD;
        }
    }

    cout << dp[0][k] % MOD << endl;
    return 0;
}
