//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|04|2024 23:14:21            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

vector<int> dist;
vector<int> parent;
vector<vector<pair<int, int>>> adj;

void bellmanFord(int n, int src) {
    dist[src] = 0;
    for (int step = 0; step < n - 1; step++) {
        for (int i = 1; i <= n; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it.first;
                int wt = it.second;
                if (((dist[u] + wt) < dist[v])) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.clear();
    dist.clear();
    adj.resize(n + 1);
    dist.resize(n + 1, inf);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, -w});
    }
    bellmanFord(n, 1);
    int x = dist[n];
    for (int i = 1; i <= n; i++) {
        for (auto it : adj[i]) {
            int u = i;
            int v = it.first;
            int wt = it.second;
            if (((dist[u] + wt) < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    dist[n] == x ? cout << -dist[n] << endl : cout << "inf" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}