//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|04|2024 02:06:23            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;


#define mod 1000000007;
#define inf 1000000000000000000;

string a, b;
int dp[5005][5005];

int LCS(int i, int j) {
    if (i < 0 or j < 0){
        if(i < 0)
            return j + 1;
        return i + 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = LCS(i - 1, j - 1);
    int makeBothSame = 1 + LCS(i - 1, j - 1);
    int deleteFromA = 1 + LCS(i - 1, j);
    int deleteFromB = 1 + LCS(i, j - 1);
    return dp[i][j] = min({makeBothSame, deleteFromA, deleteFromB});
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size(), m = b.size();
    cout << LCS(n - 1, m - 1) << "\n";
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