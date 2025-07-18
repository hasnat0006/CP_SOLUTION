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
    vector<ll> adj[n + 1];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << "NO" << '\n';
        return;
    }
    vector<ll> level(n + 1, 0), vis(n + 1, 0), par(n + 1, 0);
    function<void(ll)> dfs_for_level = [&](ll node) {
        vis[node] = 1;
        for (auto c : adj[node]) {
            if (!vis[c]) {
                par[c] = node;
                level[c] = level[node] + 1;
                dfs_for_level(c);
            }
        }
    };
    dfs_for_level(1);
    ll mx = *max_element(vf(level));
    if (mx == 1) {
        if (n > 3) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
            cout << adj[1].front() << " " << 1 << '\n';
            cout << 1 << " " << adj[1].back() << '\n';
        }
        return;
    }
    vis.assign(n + 1, 0);
    vector<int> ans[n + 1];
    dbg(level);
    ll f = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        dbg(adj[i]);
    }
    function<void(ll, ll)> dfs_for_ans = [&](ll node, ll type) {
        // 0 - up, 1 - down
        vis[node] = 1;
        for (auto c : adj[node]) {
            if (!vis[c]) {
                if (type) {
                    cnt++;
                    ans[c].push_back(node);
                    dfs_for_ans(c, !type);
                }
                else {
                    if (!f and adj[node].size() == 2) {
                        f = 1;
                        cnt++;
                        ans[c].push_back(node);
                        dfs_for_ans(c, type);
                    }
                    else {
                        cnt++;
                        ans[node].push_back(c);
                        dfs_for_ans(c, !type);
                    }
                }
            }
        }
    };
    ll start = -1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 2) {
            dbg(i, par[i]);
            if (par[i] != 0)
                start = par[i];
            else {
                if (adj[adj[i].front()].size() > adj[adj[i].back()].size())
                    start = adj[i].front();
                else
                    start = adj[i].back();
            }
        }
    }
    dbg(start);
    if (start == -1) {
        cout << "NO" << '\n';
        return;
    }
    dfs_for_ans(start, 1);
    if (cnt != n - 1 or !f) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        for (auto child : ans[i]) {
            cout << i << " " << child << '\n';
        }
    }
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