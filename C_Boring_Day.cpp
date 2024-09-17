// 2 1 11 3  7
// 2 3 14 17 24

//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|09|2024 12:18:23            !//
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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> pre(n);
    partial_sum(vf(v), pre.begin());
    dbg(pre);
    int ans = 0, i = 0, bad = 0;
    while (i < n) {
        int id = lower_bound(vf(pre), (l + bad)) - pre.begin();
        if (id < n) {
            if (pre[id] >= (l + bad) and pre[id] <= (r + bad)) {
                ans++;
                bad = pre[id];
                i = id;
            }
            else {
                bad = pre[i];
                i++;
            }
        }
        else {
            break;
        }   
    }
    cout << ans << endl;
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