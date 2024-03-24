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

int n, k;
int dp[100005];
vector<int> v;

int findMin(int nn) {
    if (nn == 0)
        return 0;
    if (dp[nn] != -1)
        return dp[nn];
    int mn = inf;
    for (int i = 1; i <= k; i++) {
        if (nn - i >= 0)
            mn = min(mn, findMin(nn - i) + abs(v[nn] - v[nn - i]));
    }
    return dp[nn] = mn;
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findMin(n - 1) << endl;
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