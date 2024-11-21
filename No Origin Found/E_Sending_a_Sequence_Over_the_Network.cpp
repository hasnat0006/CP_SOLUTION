//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|11|2024 11:05:14            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (ll i = 1; i <= n; i++) {
        if ((i - 1 > 0 and dp[i - 1]) or i == 1) {
            if (i + v[i] <= n)
                dp[i + v[i]] = true;
        }
        if (i - v[i] - 1 >= 0) {
            if (dp[i - v[i] - 1])
                dp[i] = true;
        }
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
    dbg(dp);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}