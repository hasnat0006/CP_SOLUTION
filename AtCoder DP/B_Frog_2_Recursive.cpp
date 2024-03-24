//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|03|2024 16:54:19            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), dp(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++) {
        int mn = inf;
        for (int j = 1; j <= k and (i - j >= 0); j++) {
            mn = min(mn, (dp[i - j] + abs(v[i] - v[i - j])));
            dp[i] = mn;
        }
    }
    cout << dp[n - 1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}