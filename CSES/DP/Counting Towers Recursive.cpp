//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|04|2024 00:49:08            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;
vector<vector<int>> dp(1000005, vector<int>(2, -1));

int findAns(int id, int type) {
    if (id == 0)
        return 1;
    if(dp[id][type] != -1)
        return dp[id][type];
    if (type == 0)
        return dp[id][type] = (4ll * findAns(id - 1, type) + findAns(id - 1, 1)) % MOD;
    return dp[id][type] = (2ll * findAns(id - 1, 1) + findAns(id - 1, 0)) % MOD;
}

void solve() {
    int n;
    cin >> n;
    // int dp[n][2];
    // dp[n - 1][0] = 1, dp[n - 1][1] = 1;
    // for (int i = n - 2; i >= 0; i--) {
    //     dp[i][0] = (4ll * dp[i + 1][0] + dp[i + 1][1]) % MOD;
    //     dp[i][1] = (dp[i + 1][0] + 2ll * dp[i + 1][1]) % MOD;
    // }
    // cout << (dp[0][0] + dp[0][1]) % MOD;
    // cout << "\n";
    cout << (findAns(n - 1, 0) + findAns(n - 1, 1)) % MOD;
    cout << "\n";
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