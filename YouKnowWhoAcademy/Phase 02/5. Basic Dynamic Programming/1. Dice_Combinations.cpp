//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 21:29:23            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;
const int N = 1e6 + 5;

ll dp[N];

int numberOfWay(int n) {
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll way = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0)
            way = (way + numberOfWay(n - i)) % mod;
    }
    return dp[n] = way;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << numberOfWay(n) << '\n';
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