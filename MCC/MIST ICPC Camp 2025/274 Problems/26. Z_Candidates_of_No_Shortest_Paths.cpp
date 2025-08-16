#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

typedef pair<ll, ll> pairi;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pairi>> adj(n + 5);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    map<pairi, ll> mp;

    auto dijkstra = [&](ll src) {
        vector<ll> dis(n + 5, inf), par(n + 5, -1);
        priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
        dis[src] = 0;
        pq.push({0, src});
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            for (auto [v, wt] : adj[top.second]) {
                if (dis[v] > dis[top.second] + wt) {
                    dis[v] = dis[top.second] + wt;
                    pq.push({dis[v], v});
                    par[v] = top.second;
                }
            }
        }
        dbg(dis);
        dbg(par);
        for (ll i = 1; i <= n; i++) {
            if (par[i] != -1) {
                mp[{min(i, par[i]), max(i, par[i])}]++;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        dbg(i);
        dijkstra(i);
    }
    dbg(mp);
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        for (auto [j, w] : adj[i]) {
            if (!mp.count({min(i, j), max(i, j)})) {
                cnt++;
            }
        }
    }
    cout << cnt / 2 << '\n';
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