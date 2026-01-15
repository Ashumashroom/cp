#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> st;
vector<int> cyclePath;
bool found = false;
int startNode = -1, endNode = -1;

bool dfs(vector<int>& vis, vector<int> a[], vector<int>& cycle, int node) {
    vis[node] = 1;
    cycle[node] = 1;
    st.push(node);

    for (auto it : a[node]) {
        if (cycle[it] == 1) {
            found = true;
            startNode = it;
            endNode = node;

            // build cycle path
            vector<int> temp;
            temp.push_back(startNode);
            stack<int> stCopy = st;
            vector<int> path;
            while (!stCopy.empty()) {
                path.push_back(stCopy.top());
                stCopy.pop();
            }
            reverse(path.begin(), path.end());

            // take nodes from startNode to endNode
            bool record = false;
            for (int x : path) {
                if (x == startNode) record = true;
                if (record) cyclePath.push_back(x);
                if (x == endNode) break;
            }
            cyclePath.push_back(startNode); // close the cycle
            return false;
        }
        if (vis[it] == 0) {
            if (!dfs(vis, a, cycle, it)) return false;
        }
    }

    cycle[node] = 0;
    st.pop();
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a[n + 1];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    vector<int> vis(n + 1, 0), cycle(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            while (!st.empty()) st.pop();
            if (!dfs(vis, a, cycle, i)) break;
        }
    }

    if (found) {
        cout << cyclePath.size() << "\n";
        for (int x : cyclePath) cout << x << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
