//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|03|2024 03:36:45            !//
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
    vector<int> v(n);
    map<int, int> color;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        color[v[i]] = -inf;
    }
    vector<int> dp(n + 5, 0);
    color[v[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(dp[i + 1], color[v[i]] - i + 1);
        color[v[i]] = max(color[v[i]], dp[i + 1] + i);
    }
    dbg(dp);
    cout << dp[0] << endl;
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