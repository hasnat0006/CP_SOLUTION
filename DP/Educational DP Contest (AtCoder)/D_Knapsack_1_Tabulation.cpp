//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 13:00:09            !//
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

void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].second >> v[i].first;
    vector<vector<int>> dp(n + 5, vector<int>(w + 5, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i].second > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(v[i].first + dp[i - 1][j - v[i].second], dp[i - 1][j]);
        }
    }
    cout << dp[n][w] << endl;
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