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

const ll mod = 998244353;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    set<ll> adj[n + 5];
    for (int v = 2; v <= n; v++) {
        ll u;
        cin >> u;
        adj[u].insert(v);
    }
    vector<ll> parent(n + 5), level(n + 5);
    auto bfs = [&]() {
        queue<ll> q;
        q.push(1);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto child : adj[t]) {
                q.push(child);
                parent[child] = t;
                level[child] = level[t] + 1;
            }
        }
        return;
    };

    bfs();
    map<ll, set<ll>> mp;
    set<ll> new_adj[n + 5];
    for (int i = 1; i <= n; i++)
        mp[level[i]].insert(i);
    dbg(mp);
    for (int i = 1; i <= n; i++) {
        new_adj[i] = mp[level[i] + 1];
    }
    for (int node = 2; node <= n; node++) {
        dbg(node, adj[node]);
        for(auto &child : adj[node]) {
            new_adj[node].erase(child);
        }
    }
    vector<ll> dp(n + 5, -1);
    function<ll(ll)> findAns = [&](ll node) -> ll {
        if (dp[node] != -1)
            return dp[node];
        ll cnt = 1;
        for (auto &i : new_adj[node]) {
            cnt = (cnt + findAns(i)) % mod;
        }
        return dp[node] = cnt;
    };

    ll ans = 1;
    for (auto &i : new_adj[1]) {
        ans = (ans + findAns(i)) % mod;
    }
    cout << ans << endl;
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