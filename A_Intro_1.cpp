//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|03|2024 17:08:49            !//
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

int dp[(int)1e6 + 5];

int findAns(int n) {
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    long long cnt = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0)
            cnt = (cnt + findAns(n - i)) % mod;
    }
    return dp[n] = cnt;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << findAns(n) << endl;
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