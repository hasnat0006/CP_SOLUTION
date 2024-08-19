//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|08|2024 11:42:14            !//
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int ans = 0, ind = n - 1;
    while (ind > 0 && a[ind - 1] > a[ind])
        ind--;
    for (int i = ind; i > 0; i--) {
        if (a[i - 1] <= a[i]) {
            ans += a[i] - a[i - 1] + 1;
            a[i] = a[i - 1] - 1;
        }
        else {
            a[i - 1] = max(a[i], a[i - 1] - ans);
            if (a[i - 1] == a[i])
                ans++;
        }
    }
    ans += a[0];
    cout << ans << "\n";
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