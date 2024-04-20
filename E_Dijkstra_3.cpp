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
int N = 5e5 + 5;
vector<vector<pairi>> adj(N);
vector<int> dis(N, inf);
vector<int> cnt(5e6 + 5, 0);
int mx;

void dijkstra(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    vector<int> vis(N, 0);
    dis[src] = 0;
    cnt[dis[src]]++;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        set<int> s;
        int mn = inf;
        pq.pop();
        if (vis[top.second])
            continue;
        for (auto i : adj[top.second]) {
            int v = i.first;
            s.insert(top.second);
            s.insert(v);
            mn = min(mn, i.second);
            int wt = i.second;
            if (dis[v] > dis[top.second] + wt) {
                dis[v] = dis[top.second] + wt;
                cnt[dis[v]]++;
                // cerr << "---" << endl;
                // cerr << top.second << " " << v << " " << dis[v] << endl;
                mx = max(mx, dis[v]);
                pq.push({dis[v], v});
            }
        }
        if (s.size() == 1) {
            // cerr << top.second << endl;
            mx = mn, cnt[mn]++;
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while (q--) {
        int x;
        cin >> x;
        dis.assign(N, inf);
        mx = 0;
        cnt.assign(5e6 + 5, 0);
        dijkstra(x);
        // cerr << mx << endl;
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