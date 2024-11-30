//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|11|2024 10:35:52            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll dp[505][505];

ll findMinimumCut(ll n, ll m) {
    if (n == m)
        return 0;
    if (n == 1)
        return m - 1;
    if (m == 1)
        return n - 1;
    if (dp[n][m] != -1)
        return dp[n][m];
    ll ans = inf;
    for (int i = 1; i < m; i++) {
        ll temp = findMinimumCut(n, i) + findMinimumCut(n, m - i) + 1;
        ans = min(ans, temp);
    }
    for (int i = 1; i < n; i++) {
        ll temp = findMinimumCut(i, m) + findMinimumCut(n - i, m) + 1;
        ans = min(ans, temp);
    }
    return dp[n][m] = ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << findMinimumCut(n, m) << '\n';
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