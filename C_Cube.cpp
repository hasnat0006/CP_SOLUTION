//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 18:09:19            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const ll N = 12;
ll arr[N][N][N];
ll dp[N][1 << 12][1 << 12];
ll n;

ll findMinAns(ll x, ll masky, ll maskz) {
    if (x < 0)
        return 0;
    if (dp[x][masky][maskz] != -1)
        return dp[x][masky][maskz];
    ll ans = inf;
    for (int j = 0; j < n; j++) {
        if (!(masky & (1 << j))) {
            for (int k = 0; k < n; k++) {
                if (!(maskz & (1 << k))) {
                    ans = min(ans, arr[x][j][k] + findMinAns(x - 1, masky | (1 << j) , maskz | (1 << k)));
                }
            }
        }
    }
    return dp[x][masky][maskz] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> arr[i][j][k];
            }
        }
    }
    cout << findMinAns(n - 1, 0, 0) << endl;
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