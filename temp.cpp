//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|04|2024 16:04:04            !//
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

void bellmonFord(int n, int m, int src) {
    dist[src] = 0;
    for (int step = 0; step < n; step++) {
        for (int i = 1; i <= n; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it.first;
                int wt = it.second;
                if (dist[u] != inf && ((dist[u] + wt) < dist[v])) {
                    if (step == n - 1) {
                        cout << "Negative cycle found" << endl;
                        return;
                    }
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == inf ? 30000 : dist[i]) << " ";
    cout << endl;
}

void solve() {
    int node, edges, u, v, wt;
    cin >> node >> edges;
    dist.resize(node + 1, inf);
    parent.resize(node + 1, -1);
    adj.resize(node + 1);
    for (int i = 0; i < edges; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    bellmonFord(node, edges, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}