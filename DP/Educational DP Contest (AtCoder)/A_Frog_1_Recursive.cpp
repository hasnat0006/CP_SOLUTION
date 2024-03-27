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

int findMin(int n, vector<int> &heights, vector<int> &dp){
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int left = findMin(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = (int) 1e18;
    if(n > 1)
            right = findMin(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    // dbg(left, right);
    return dp[n] = min(left, right);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n, -1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findMin(n - 1, v, dp) << endl;
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