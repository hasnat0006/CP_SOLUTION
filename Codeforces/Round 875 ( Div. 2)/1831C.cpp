//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|03|2024 00:49:57            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

map<int, vector<int>> adj;
map<int, int> visited, parent, level;
map<pair<int, int>, int> order;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto child : adj[k]) {
            if (!visited[child]) {
                if (k == 1)
                    level[child] = 1;
                else {
                    int preV = order[{k, parent[k]}];
                    int curr = order[{child, k}];
                    level[child] = (preV > curr) ? level[k] + 1 : level[k];
                }
                q.push(child);
                visited[child] = 1;
                parent[child] = k;
            }
        }
    }
}

void solve() {
    adj.clear();
    visited.clear();
    level.clear();
    order.clear();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v});
        adj[v].push_back({u});
        order[{u, v}] = order[{v, u}] = i;
    }
    bfs(1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, level[i]);
    }
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}