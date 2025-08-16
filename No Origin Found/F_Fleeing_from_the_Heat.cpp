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
    vector<ll> temp(n + 1), change(n + 5, -1);
    map<ll, ll> needToChange;
    for (int i = 1; i <= n; i++) {
        cin >> temp[i];
        if (temp[i] > m) {
            needToChange[i] = 1;
            change[i] = 0;
        }
    }
    vector<ll> adj[n + 5];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> move(n + 5), depth(n + 5, 0);
    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        vector<pair<ll, ll>> t;
        for (auto v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            if (change[v] != -1)
                t.push_back({change[v] + 1, v});
            if (change[v] >= 0)
                depth[u] = max(depth[v] + 1, depth[u]);
        }
        sort(vf(t));
        dbg(t);
        if (t.size()) {
            change[u] = t.back().first;
            depth[u] = max(depth[u], depth[t.back().second] + 1);
        }
        if (t.size() > 1) {
            t.pop_back();
            for (auto [val, node] : t) {
                change[u] += val;
                change[u] += depth[node] + 1;
                dbg(u, val, depth[node]);
            }
        }
        dbg(u, depth[u], change[u]);
    };

    dfs(1, 0);
    dbg(needToChange);
    dbg(change);

    cout << max(0LL, change[1]) << '\n';
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