//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|03|2024 02:01:08            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

string a, b;
int dp[3005][3005], mark[3005][3005];

int LCS(int i, int j) {
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        mark[i][j] = 1ll, dp[i][j] = 1ll + LCS(i - 1, j - 1);
    else {
        int up = LCS(i - 1, j), left = LCS(i, j - 1);
        mark[i][j] = (up > left) ? 2ll : 3ll;
        dp[i][j] = max(up, left);
    }
    return dp[i][j];
}

void printLCS(int i, int j) {
    if (i < 0 or j < 0)
        return;
    if (mark[i][j] == 1)
        printLCS(i - 1, j - 1), cout << a[i];
    else if (mark[i][j] == 2)
        printLCS(i - 1, j);
    else if (mark[i][j] == 3)
        printLCS(i, j - 1);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size(), m = b.size();
    LCS(n - 1, m - 1);
    printLCS(n - 1, m - 1);
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