//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|11|2024 23:43:46            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll n;
ll grid[17][17];
ll dp[17][(1 << 17) + 1];

ll NumberOfWay(ll man, ll bitmask) {
    if ((1 << n) - 1 == bitmask)
        return 0;
    if (man < 0)
        return 0;
    if (dp[man][bitmask] != -1)
        return dp[man][bitmask];

    ll way = 0;
    for (ll woman = 0; woman < n; woman++) {
        if ((bitmask & (1 << woman)))
            continue;  // already take this woman
        way = max(way, grid[man][woman] + NumberOfWay(man - 1, (bitmask | (1 << woman))));
    }
    return dp[man][bitmask] = way;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    // tracking taken female as bitmask
    cout << NumberOfWay(n - 1, 0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}