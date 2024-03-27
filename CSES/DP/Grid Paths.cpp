//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 01:35:30            !//
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

int add(int x, int y) {
    int ans = (x + y) % mod;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &i : grid)
        cin >> i;
    if (grid[0][0] == '*' or grid[n - 1][n - 1] == '*') {
        cout << 0 << endl;
        return;
    }
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[n - 1][n - 1] = 1;
    for (int r = n - 1; r >= 0; r--) {
        for (int c = n - 1; c >= 0; c--) {
            if (grid[r][c] == '*')
                continue;
            if (r < n - 1)
                dp[r][c] = add(dp[r][c], dp[r + 1][c]);
            if (c < n - 1)
                dp[r][c] = add(dp[r][c], dp[r][c + 1]);
        }
    }
    cout << dp[0][0] << endl;
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