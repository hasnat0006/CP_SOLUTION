//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|03|2024 01:25:30            !//
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

void solve() {
    int x, y, r;
    cin >> x >> y >> r;
    if (y > x)
        swap(x, y);
    int diffXY = abs(x - y);
    bitset<64> X(x), Y(y), R(0);
    int cnt = 0;
    for (int i = 63; i >= 0; i--) {
        if (X[i] == 1 && Y[i] == 0) {
            if (cnt == 0) {
                cnt = 1;
                continue;
            }
            else {
                R[i] = 1;
                if (R.to_ullong() <= r)
                    X[i] = 0, Y[i] = 1;
                else
                    R[i] = 0;
            }
        }
    }
    // cout << X.to_ullong() << " " << Y.to_ullong() << " " << R.to_ullong() << endl;
    x = X.to_ullong(), y = Y.to_ullong();
    cout << abs(x - y) << endl;
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