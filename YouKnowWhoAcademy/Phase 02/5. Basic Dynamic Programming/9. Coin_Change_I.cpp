//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 21:48:04            !//
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

const int mod = 100000007;
const ll inf = 1e18;

ll n, k;
vector<int> value, cnt;
ll dp[55][1005];

ll ways_to_make_k(int i, int k, int nisi = 0) {
    if (k == 0)
        return 1;
    if (i == -1)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int ways = 0;
    for (int taken = 0; taken <= cnt[i]; taken++) {
        if (k - value[i] * taken >= 0)
            ways =(ways + ways_to_make_k(i - 1, k - value[i] * taken)) % mod;
    }
    return dp[i][k] = ways;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    value.resize(n), cnt.resize(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    for (int i = 0; i < n; i++)
        cin >> cnt[i];
    cout << ways_to_make_k(n - 1, k) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}