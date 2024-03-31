//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 22:24:45            !//
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
        cin >> v[i].second;
    for (int i = 1; i <= n; i++)
        cin >> v[i].first;
    vector<int> dp(w + 5, 0);
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i] = dp[i - 1];
            if(i - v[j].second >= 0)
                dp[i] = max(dp[i], dp[i - v[j].second] + v[j].first);
        }
    }
    cout << dp[w] << endl;
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