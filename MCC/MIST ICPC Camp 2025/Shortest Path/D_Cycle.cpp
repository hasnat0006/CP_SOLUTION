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
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 3];
    vector<ll> possible1;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (v == 1)
            possible1.push_back(u);
    }

    vector<ll> dis(n + 5, -1), vis(n + 5);

    queue<ll> q;
    q.push(1);
    dis[1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (vis[t])
            continue;
        vis[t] = 1;
        for (auto v : adj[t]) {
            q.push(v);
            if (dis[v] == -1)
                dis[v] = dis[t] + 1;
        }
    }
    ll ans = inf;
    for (int i : possible1) {
        if (vis[i])
            ans = min(ans, dis[i] + 1);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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