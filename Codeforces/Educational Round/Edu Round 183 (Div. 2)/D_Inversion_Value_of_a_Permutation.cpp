//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|10|2025 22:47:59            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
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
const ll N = 30 + 5;
const ll K = (N * (N - 1)) / 2;

ll dp[N][K], track[N][K];

ll con_sum(ll n) { return (n * (n - 1)) / 2; }

ll is_possible(ll n, ll k) {
    if (k < 0)
        return 0;
    if (k == con_sum(n)) {
        track[n][k] = n;
        return 1;
    }
    if (k > con_sum(n))
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];

    for (int i = 1; i < n; i++) {
        ll kk = con_sum(i);
        if (is_possible(n - i, k - kk)) {
            track[n][k] = i;
            return dp[n][k] = 1;
        }
    }
    return dp[n][k] = 0;
};

void solve() {
    ll n, k;
    cin >> n >> k;
    k = con_sum(n) - k;
    if (!is_possible(n, k)) {
        cout << 0 << '\n';
        return;
    }
    ll curLast = n;
    for (int len = track[n][k]; n > 0; len = track[n][k]) {
        for (int i = curLast - len + 1; i <= curLast; i++)
            cout << i << " ";
        curLast -= len;
        n -= len;
        k -= con_sum(len);
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    memset(track, -1, sizeof(track));
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}