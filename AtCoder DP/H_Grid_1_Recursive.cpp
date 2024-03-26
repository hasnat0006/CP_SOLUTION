//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 15:05:12            !//
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

int n, m;
char grid[1005][1005];
int dp[1005][1005];

int totalWay(int x, int y) {
    if (x == 1 and y == 1)
        return 1;
    if (x < 1 or y < 1 or grid[x][y] == '#')
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int up = totalWay(x - 1, y);
    int left = totalWay(x, y - 1);
    return dp[x][y] = (up + left) % mod;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    }
    cout << totalWay(n, m) << endl;
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