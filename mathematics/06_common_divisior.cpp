#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int MAX = *max_element(a.begin(), a.end());
    vector<int> freq(MAX + 1, 0);

    // Count frequency of each number
    for (int x : a) freq[x]++;

    int ans = 1;
    // For each possible divisor d, count how many numbers are multiples of d
    for (int d = 1; d <= MAX; d++) {
        int cnt = 0;
        for (int multiple = d; multiple <= MAX; multiple += d)
            cnt += freq[multiple];

        if (cnt >= 2) ans = d;
    }

    cout << ans << "\n";
    return 0;
}
