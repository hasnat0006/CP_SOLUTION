//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|04|2024 23:16:01            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    int left = n;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        left += (x == y) ? -1 : -2;
    }
    int dp[left + 5];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= left; i++){
        dp[i] = (dp[i - 1] + ((2 * (i - 1) * dp[i - 2])) % mod) % mod;
    }
    cout << dp[left] << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}