#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll int

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> adj[n + 5];
    vector<int> color(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<ll, ll>> qu[n + 5];
    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        qu[x].push_back({y, i});
    }

    unordered_map<int, int> mp[n + 5];
    map<int, int> ulta[n + 5];
    vector<ll> ans(q);
    auto merging = [&](ll c, ll u) {                                                                                                             
        for (auto &[i, cnt] : mp[c]) {
            ll t = mp[u][i];
            mp[u][i] += cnt;
            if (ulta[u][t] != 0)
                ulta[u][t]--;
            ulta[u][t + cnt]++;
        }
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        mp[u][color[u]]++;
        ulta[u][1] = 1;
        for (auto &c : adj[u]) {
            if (c == p)
                continue;
            dfs(c, u);
            if (mp[c].size() >= mp[u].size()) {
                swap(mp[c], mp[u]);
                swap(ulta[u], ulta[c]);
            }
            merging(c, u);
            mp[c].clear();
        }
        for (auto &[l, i] : qu[u]) {
            auto it = ulta[u].lower_bound(l);
            while (it != ulta[u].end()) {
                ans[i] += (it->second);
                it++;
            }
        }
    };
    dfs(1, 0);
    for (auto i : ans)
        cout << i << "\n";
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