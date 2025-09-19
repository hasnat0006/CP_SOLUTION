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
    vector<ll> adj[n + 5];
    for (int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> dis(n + 5, 0), vis(n + 5, 0);
    auto bfs = [&](ll src) {
        dis.assign(n + 5, -1), vis.assign(n + 5, 0);
        queue<ll> q;
        q.push(src);
        dis[src] = 0;
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
        dbg(src, dis);
    };
    for (int i = 1; i <= n; i++) {
        bfs(i);
        ll cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dis[j] == 2)
                cnt++;
        }
        cout << cnt << '\n';
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