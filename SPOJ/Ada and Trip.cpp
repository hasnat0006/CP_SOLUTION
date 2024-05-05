//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|04|2024 16:22:35            !//
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

typedef pair<int, int> pairi;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pairi>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while (q--) {
        int x;
        cin >> x;
        vector<int> dis(n + 1, inf);
        auto dijkstra = [&](int src) {
            priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
            dis[src] = 0;
            pq.push({0, src});
            while (pq.size()) {
                auto top = pq.top();
                pq.pop();
                if (top.first != dis[top.second])
                    continue;
                for (auto i : adj[top.second]) {
                    int v = i.first;
                    int wt = i.second;
                    if (dis[v] > dis[top.second] + wt) {
                        dis[v] = dis[top.second] + wt;
                        pq.push({dis[v], v});
                    }
                }
            }
        };
        dijkstra(x);
        int mx = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (dis[i] != inf)
                mx = max(mx, dis[i]);
            cnt[dis[i]]++;
        }
        cout << mx << " " << cnt[mx] << endl;
    }
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