//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 20:10:32            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int MOD(int x, int y) { return ((x % mod) + (y % mod)) % mod; }

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> v(n + 1), pre(n + 1);
    vector<pair<int, int>> vp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> x >> y;
        vp[i].first = max(0ll, i - x - 1);
        vp[i].second = min(n, i + y);
    }
    partial_sum(vf(v), pre.begin());
    accumulate(vf(pre), MOD);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int start = vp[j].first, end = vp[j].second;
            v[j] = pre[end] - pre[start];
            v[j] %= mod;
        }
        partial_sum(vf(v), pre.begin());
        accumulate(vf(pre), MOD);
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
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