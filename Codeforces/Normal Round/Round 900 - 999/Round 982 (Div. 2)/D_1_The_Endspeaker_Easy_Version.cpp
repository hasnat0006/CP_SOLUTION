//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|11|2024 08:50:54            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];

    ll mx = *max_element(vf(a));
    if (mx > b.front()) {
        cout << -1 << '\n';
        return;
    }

    vector<ll> prefix(n), cost(m);
    partial_sum(vf(a), prefix.begin());
    iota(vf(cost), 0);
    reverse(vf(cost));


    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, inf));

    for (ll i = m; i >= 0; i--) {
        dp[n][i] = 0;
    }

    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = m - 1; j >= 0; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            if (b[j] >= a[i]) {
                ll val = b[j] - a[i] + prefix[i];
                ll id = upper_bound(prefix.begin(), prefix.end(), val) - prefix.begin();
                dp[i][j] = min(dp[i][j], dp[id][j] + cost[j]);
            }
        }
    }

    cout << (dp[0][0] >= inf ? -1 : dp[0][0])  << '\n';
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