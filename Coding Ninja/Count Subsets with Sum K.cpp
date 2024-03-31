//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 14:41:34            !//
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

vector<vector<int>> dp(110, vector<int>(5000, -1));

int count(int i, int k, vector<int>& v) {
    if(i == 0){
        if(k == 0 and v[i]== 0)
            return 2;
        if(k == 0)
            return 1;
        return k == v[i];
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int notTake = count(i - 1, k, v), take = 0;
    if (k - v[i] >= 0)
        take = count(i - 1, k - v[i], v);
    // cout << i << " " << k << " " << take << " " << notTake << endl;
    return dp[i][k] = take + notTake;
}

int findWays(vector<int>& arr, int k) { return count(arr.size() - 1, k, arr); }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << findWays(v, k);
    // vector<vector<long long>> dp(105, vector<long long>(100005, 0));
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 1;
    // if (v[0] <= k)
    //     dp[0][v[0]] = 1;
    // for (int i = 1; i < n; i++) {
    //     for (int sum = 0; sum <= k; sum++) {
    //         dbg("1");
    //         int notpick = dp[i - 1][sum], pick = 0;
    //         dbg("2");
    //         if (sum - v[i] >= 0)
    //             pick = dp[i - 1][sum - v[i]];
    //         dp[i][sum] = pick + notpick;
    //     }
    // }
    // cout << dp[n - 1][k] << endl;
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