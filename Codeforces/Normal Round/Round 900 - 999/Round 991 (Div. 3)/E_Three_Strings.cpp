//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    ll n = a.size(), m = b.size(), o = c.size();

    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, -1));
    function<ll(ll, ll)> findMinAns = [&](ll i, ll j) -> ll {
        if (i == n and j == m or i + j >= o)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        ll ans1 = inf, ans2 = inf;
        ll k = i + j;
        if (i < n) {
            if (c[k] == a[i])
                ans1 = findMinAns(i + 1, j);
            else {
                ans1 = min(ans1, 1LL + findMinAns(i + 1, j));
            }
        }
        if (j < m) {
            if (c[k] == b[j])
                ans2 = findMinAns(i, j + 1);
            else {
                ans2 = min(ans2, 1LL + findMinAns(i, j + 1));
            }
        }
        return dp[i][j] = min(ans1, ans2);
    };
    cout << findMinAns(0, 0) << '\n';
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