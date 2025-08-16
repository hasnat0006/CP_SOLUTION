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
    ll n;
    cin >> n;
    vector<ll> adj[n + 5];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> node(n + 5), parent(n + 5);
    function<ll(ll, ll)> dfs = [&](ll u, ll par) -> ll {
        ll cnt = 1;
        for (auto v : adj[u]) {
            if (v == par)
                continue;
            parent[v] = u;
            cnt += dfs(v, u);
        }
        return node[u] = cnt;
    };
    dfs(1, -1);
    ll F = 0, S = 0;
    ll des = n, c = 0;
    while (parent[des] != 1) {
        des = parent[des];
        c++;
    }
    des = n;
    map<ll, ll> used;
    used[n] = 1;
    ll temp = c / 2;
    while (temp--) {
        des = parent[des];
        used[des] = 1;
    }
    S = node[des];
    F = n - S;
    cout << (S >= F ? "Snuke" : "Fennec") << '\n';
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