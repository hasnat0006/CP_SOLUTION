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

void solve() {
    ll n, s, e;
    cin >> n >> s >> e;
    ll m;
    cin >> m;
    vector<ll> adj[n + 5];
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dbg(n, s, e);
    for (int i = 1; i <= n; i++) {
        dbg(adj[i]);
    }
    map<ll, map<ll, ll>> dis;
    function<void(ll)> bfs = [&](ll u) {
        vector<ll> vis(n + 5, 0), dep(n + 5, 0), poped(n + 5, 0);
        queue<ll> q;
        q.push(s);
        dis[s][dep[s]] = 1;
        vis[s] = 1;
        while (q.size()) {
            dbg(q);
            auto node = q.front();
            q.pop();
            for (auto v : adj[node]) {
                dbg(v, node);
                dep[v] = dep[node] + 1;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
                if (!poped[v]) {
                    dis[v][dep[v]] += dis[node][dep[node]];
                    dis[v][dep[v]] %= mod;
                }
            }
            poped[node] = 1;
            dbg(dis);
        }
    };
    bfs(s);
    // dbg(dis);
    dbg(dis[e]);
    cout << dis[e].begin()->second << '\n';
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