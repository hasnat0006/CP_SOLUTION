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
    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> edge(n + 5, 0);
    ll edgeNode = 0;

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1)
            edgeNode++;
    }

    dbg(edge);
    dbg(edgeNode);
    ll ans = inf;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (auto v : adj[i]) {
            if (adj[v].size() == 1)
                cnt++;
        }
        dbg(cnt, edge[i]);
        ans = min(ans, edgeNode - cnt - edge[i]);
        dbg(i, ans);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}