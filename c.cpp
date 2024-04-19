//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|04|2024 00:28:48            !//
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
int N = 300000 + 5;
vector<vector<pairi>> adj(N);
vector<vector<int>> dis(2, vector<int>(N, inf));

void dijkstra(int src, int id) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    dis[id][src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            int v = i.first;
            int wt = i.second;
            if (dis[id][v] > max(dis[id][top.second], wt)) {
                dis[id][v] = max(dis[id][top.second], wt);
                pq.push({dis[id][v], v});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = inf;
    vector<pair<int,pairi>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (min(u, v) == 1 and max(u, v) == n) {
            ans = min(ans, w);
            continue;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    for(auto i : edges) {
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(w >= max(dis[0][v], dis[1][u])) {
            ans = min(ans, w + max(dis[0][v], dis[1][u]));
        }
        if(w >= max(dis[0][u], dis[1][v])) {
            ans = min(ans, w + max(dis[0][u], dis[1][v]));
        }
    }
    cout << ans << endl;
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