//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 21:20:01            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1000000007;
#define inf 1000000000000000000;

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++) {
        if (v[0] == 0 or v[0] == i)
            dp[0][i] = 1;
    }
    auto isValid = [&](int x) {
        if (x > 0 and x <= m)
            return true;
        return false;
    };
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i] != 0 and v[i] != j)
                continue;
            for (int k = j - 1; k <= j + 1; k++) {
                if (isValid(k))
                    dp[i][j] = mod_add(dp[i][j], dp[i - 1][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) 
        ans = mod_add(ans, dp[n - 1][i]);
    cout << ans << endl;
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