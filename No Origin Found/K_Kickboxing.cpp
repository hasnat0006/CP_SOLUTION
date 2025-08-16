#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 998244353;
const ll inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (int pre = 0; pre <= n; pre++) {
        dp[0][pre] = 1;
    }

    for (int num = 1; num <= n; num++) {
        for (int pre = 1; pre <= n; pre++) {
            ll ans = 0;
            for (int i = min(pre, num); i > 0; i--) {
                if (i != k and num - i >= 0) {
                    ans += dp[num - i][i];
                    ans %= mod;
                }
            }
            dp[num][pre] = ans;
        }
    }

    cout << dp[n][n] << '\n';
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