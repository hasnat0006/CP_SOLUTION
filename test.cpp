//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|07|2025 19:47:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, q, r;
    cin >> n >> q >> r;
    vector<ll> adj[n + 5], v(n + 5), level(n + 5, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<ll, ll>> query[n + 5];
    for (int i = 0; i < q; i++) {
        ll u, l;
        cin >> u >> l;
        query[u].push_back({l, i});
    }

    map<ll, ll> node[n + 5];
    vector<ll> ans(q);
    auto merging = [&](ll c, ll u) {
        if (node[c].size() > node[u].size())
            swap(node[c], node[u]);
        for (auto &[l, AND] : node[c]) {
            node[u][l] = (node[u].count(l) ? (node[u][l] & AND) : AND);
        }
        return;
    };

    auto process_ans = [&](ll u) {
        for (auto &[l, i] : query[u]) {
            ll req_level = l + level[u];
            ans[i] = node[u].count(req_level) ? node[u][req_level] : -1;
        }
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        level[u] = level[p] + 1;
        node[u][level[u]] = v[u];
        for (auto c : adj[u]) {
            if (c == p)
                continue;
            dfs(c, u);
            merging(c, u);
        }
        process_ans(u);
    };
    dfs(r, 0);
    for (auto i : ans)
        cout << i << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}