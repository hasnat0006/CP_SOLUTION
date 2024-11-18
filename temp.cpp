//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|11|2024 23:30:55            !//
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
    ll n;
    cin >> n;
    vector<ll> adj[n + 5];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll way = 0;
    map<pair<ll, ll>, bool> vis;
    function<ll(ll, ll)> dfs =
        [&](ll x, ll color) -> ll {  // color = 1(black), 0(white)
        if (vis.count({x, color}))
            return 0;
        vis[{x, color}] = 1;
        ll tempWay = 0;
        for (auto child : adj[x]) {
            tempWay += 1 + dfs(child, 0);
            if (color == 0)
                tempWay += 1 + dfs(child, 1);
        }
        return tempWay;
    };

    cout << dfs(1, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}