//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|04|2024 02:33:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// #define int   long long
// #define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - v[j] >= 0)
                dp[i] = (dp[i] + dp[i - v[j]]) % mod;
        }
    }
    cout << dp[k] << endl;
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