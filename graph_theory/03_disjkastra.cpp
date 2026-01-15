#include <iostream>
#include <vector>
#include <queue>
#include <climits> // for LLONG_MAX
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> a[n+1];
    for(int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back({y, w});
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<long long> dis(n+1, LLONG_MAX);

    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();

        if(cost > dis[node]) continue; 

        for(auto it: a[node]) {
            int adj = it.first;
            long long wt = it.second;
            if(cost + wt < dis[adj]) {
                dis[adj] = cost + wt;
                pq.push({dis[adj], adj});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(dis[i] == LLONG_MAX) cout << "-1 ";
        else cout << dis[i] << " ";
    }
}
