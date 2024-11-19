//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 11:07:53            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1e5 + 5;

vector<ll> adj[N];

ll dp[N][2];

void dfs(ll u, ll p) {
    dp[u][0] = dp[u][1] = 1;
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % mod;
            dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
        }
    }
    return;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
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