//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 19:26:09            !//
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

int factors(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a * a <= n; a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    int gcd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        gcd = __gcd(gcd, x);
    }
    int ans = 1;
    while (gcd > 1) {
        int r = factors(gcd);
        int cnt = 0;
        while (gcd % r == 0) {
            cnt++;
            gcd /= r;
        }
        ans *= (cnt + 1);
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