//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
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
    ll n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> mn(n, vector<ll>(m, inf));
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(m, 0)));
    for (ll i = 0; i < m; i++) {
        dp[0][0][i] = arr[0][i] + k * i;
        mn[0][0] = min(mn[0][0], dp[0][0][i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int s = 0; s < m; s++) {
                if (!i and !j)
                    continue;
                dp[i][j][s] = (j > 0 ? dp[i][j - 1][s] : inf);
                ll val = (i > 0 ? mn[i - 1][j] : inf);
                dp[i][j][s] =
                    min(dp[i][j][s], val + k * s) + arr[i][(j + s) % m];
                mn[i][j] = min(mn[i][j], dp[i][j][s]);
            }
        }
    }
    cout << mn[n - 1][m - 1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}