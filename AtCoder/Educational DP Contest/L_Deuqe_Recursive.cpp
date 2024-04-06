//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|04|2024 15:01:17            !//
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

#define mod 1000000007;
#define inf 1000000000000000000;

int n;
vector<int> v;

int dp[3005][3005];

int findAns(int i, int j) {
    // base case
    if (i == j)
        return v[i];
    if (i + 1 == j)
        return max(v[i], v[j]);
    if (dp[i][j] != -1)
        return dp[i][j];
    int first = v[i] + min(findAns(i + 2, j), findAns(i + 1, j - 1));
    int second = v[j] + min(findAns(i + 1, j - 1), findAns(i, j - 2));
    return dp[i][j] = max(first, second);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum = accumulate(vf(v), 0ll);
    cout << 2 * findAns(0, n - 1) - sum << endl;
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