#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> pq; // {frequency, -value}
    vector<int> result;

    auto add = [&](int x) {
        freq[x]++;
        pq.push({freq[x], -x});
    };

    auto remove = [&](int x) {
        freq[x]--;
        pq.push({freq[x], -x}); // still push, lazy cleanup
    };

    for (int i = 0; i < n; ++i) {
        add(a[i]);
        if (i >= k) remove(a[i - k]);

        if (i >= k - 1) {
            // Clean up outdated top entries
            while (!pq.empty()) {
                int f = pq.top().first;
                int x = -pq.top().second;
                if (freq[x] == f) break; // valid
                pq.pop(); // outdated
            }
            result.push_back(-pq.top().second);
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i) cout << " ";
        cout << result[i];
    }
    cout << "\n";
    return 0;
}
