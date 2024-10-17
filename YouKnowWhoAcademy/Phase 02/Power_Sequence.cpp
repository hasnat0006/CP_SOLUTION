//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|10|2024 00:58:16            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

__int128_t binaryExp(__int128_t base, __int128_t power, int MOD = mod) {
    __int128_t res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

int findAns(int a, int x) { return log10l(x) / log10l(a); }

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    int cnt = LLONG_MAX;
    for (int c = 2;; c++) {
        int possible = findAns(c, 1e13);
        cnt = c;
        if (possible < n - 1)
            break;
    }
    dbg(cnt);
    cnt = min(cnt, 31625LL);
    int ans = accumulate(vf(v), 0LL) - n;
    for (int c = 1; c <= cnt; c++) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            __int128_t num = binaryExp(c, i);
            if (num > 1e18) {
                cost = LLONG_MAX;
                break;
            }
            else
                cost += abs((int)num - v[i]);
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
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