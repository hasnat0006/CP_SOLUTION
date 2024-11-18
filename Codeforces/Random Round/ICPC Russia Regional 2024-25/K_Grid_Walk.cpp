//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|11|2024 19:50:50            !//
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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> gcdA(n + 1), gcdB(n + 1);
    for (ll i = 1; i <= n; i++) {
        gcdA[i] = __gcd(i, a);
        gcdB[i] = __gcd(i, b);
    }
    ll grid[n + 1][n + 1];
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= n; i++) {
        grid[1][i] = grid[1][i - 1] + gcdA[i] + gcdB[1];
        grid[i][1] = grid[i - 1][1] + gcdB[i] + gcdA[1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int left = grid[i][j - 1];
            int up = grid[i - 1][j];
            grid[i][j] = min(left, up) + gcdA[j] + gcdB[i];
        }
    }
    cout << grid[n][n] << '\n';
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