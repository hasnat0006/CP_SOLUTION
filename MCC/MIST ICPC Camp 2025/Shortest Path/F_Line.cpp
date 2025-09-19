#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> adj[n + 5];
    for (int i = 2; i <= n; i++) {
        adj[i].push_back(i - 1);
        adj[i - 1].push_back(i);
    }
    adj[a].push_back(b);
    adj[b].push_back(a);

    for (int i = 1; i <= n; i++)
        dbg(i, adj[i]);

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
    vector<ll> ans(2 * n + 5);
    for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = 1; j <= n; j++) {
            ans[dis[j]]++;
        }
    }

    for(int i = 1; i < n; i++) {
        cout << ans[i] / 2 << '\n';
    }

    dbg(ans);
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