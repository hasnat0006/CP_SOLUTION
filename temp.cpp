//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|11|2024 12:11:10            !//
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
    ll n, m;
    cin >> n >> m;
    ll grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    if((n + m) % 2 == 0){
        cout << "NO" << '\n';
        return;
    }

    vector<vector<ll>> dpMN(n + 1, vector<ll>(m + 1)), dpMX(n + 1, vector<ll>(m + 1));

    dpMN[0][0] = dpMX[0][0] = grid[0][0];
    for (ll i = 1; i < n; i++)
        dpMN[i][0] = dpMX[i][0] = grid[i][0] + dpMN[i - 1][0];
    for(ll i = 1; i < m; i++)
        dpMN[0][i] = dpMX[0][i] = grid[0][i] + dpMN[0][i - 1];

    for(ll i = 1; i < n; i++) {
        for(ll j = 1; j < m; j++) {
            dpMN[i][j] = grid[i][j] + min(dpMN[i - 1][j], dpMN[i][j - 1]);
            dpMX[i][j] = grid[i][j] + max(dpMX[i - 1][j], dpMX[i][j - 1]);
        }
    }
    ll low = dpMN[n - 1][m - 1];
    ll high = dpMX[n - 1][m - 1];

    if(low <= 0 and high >= 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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