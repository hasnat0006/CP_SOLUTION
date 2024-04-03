//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 01:18:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int n;
    cin >> n;
    vector<float> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<float>> dp(3000, vector<float>(3000, -1.0));
    dp[0][0] = 1 - v[0];
    dp[0][1] = v[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3000; j++) {
            dp[i][j] += (1 - v[i]) * dp[i - 1][j];
            if (j > 0)
                dp[i][j] += v[i] * dp[i - 1][j - 1];
        }
    }
    float ans = 0;
    for(int i = n / 2 + 1; i < 3000; i++){
        ans += dp[n - 1][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
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