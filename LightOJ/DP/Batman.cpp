//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 23:03:23            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

string a, b, c;
int dp[55][55][55];

int LCS(int i, int j, int k) {
    if (i < 0 or j < 0 or k < 0)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (a[i] == b[j] and a[i] == c[k] and b[j] == c[k])
        return dp[i][j][k] = 1 + LCS(i - 1, j - 1, k - 1);
    return dp[i][j][k] = max({LCS(i - 1, j, k), LCS(i, j - 1, k), LCS(i, j, k - 1)});
}

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> a >> b >> c;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            for (int k = 1; k <= c.size(); k++) {
                if (a[i - 1] == b[j - 1] and a[i - 1] == c[k - 1] and b[j - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    cout << dp[a.size()][b.size()][c.size()] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}