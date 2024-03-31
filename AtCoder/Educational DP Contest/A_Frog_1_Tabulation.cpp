//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|03|2024 16:06:03            !//
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
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++) {
        int first = dp[i - 1] + abs(v[i] - v[i - 1]);
        int second = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(first, second);
    }
    dbg(dp);
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