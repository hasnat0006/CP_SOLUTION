//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|07|2025 16:27:04            !//
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
    ll w, n, k;
    cin >> w >> n >> k;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int dp[55][55][10000];
    memset(dp, -1, sizeof(dp));

    function<ll(ll, ll, ll)> KNAPSACK = [&](ll i, ll r, ll wt) -> ll {
        if (i < 0 or r <= 0)
            return 0LL;
        if (dp[i][r][wt] != -1)
            return dp[i][r][wt];
        ll not_take = KNAPSACK(i - 1, r, wt);
        ll take = 0;
        if (wt - v[i].first >= 0)
            take = KNAPSACK(i - 1, r - 1, wt - v[i].first) + v[i].second;
        return dp[i][r][wt] = max(take, not_take);
    };

    cout << KNAPSACK(n - 1, k, w) << '\n';
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