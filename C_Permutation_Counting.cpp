//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|04|2024 21:43:06            !//
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int sum = accumulate(vf(a), 0LL);
    int avg = (sum + k) / n;
    int below_avg = 0, BAS = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < avg) {
            below_avg++;
            BAS += a[i];
        }
    }
    // BAS tai amr drkr;
    if (below_avg != 0) {
        // dbg(k, below_avg);
        int per = (k + BAS) / below_avg;
        per = min(per, *max_element(vf(a)));
        dbg(per, avg);
        for (int i = 0; i < n; i++) {
            if (a[i] < avg) {
                k -= (per - a[i]);
                a[i] = per;
            }
        }
        dbg(a);
        for (int i = 0; i < n and k > 0; i++) {
            if (a[i] < avg) {
                a[i]++;
                k--;
            }
        }
        dbg(a);
        dbg(k);
    }
    int per = k / n;
    for (int i = 0; i < n; i++) {
        a[i] += per;
        k -= per;
    }
    for (int i = 0; i < n and k > 0; i++) {
        a[i]++;
        k--;
    }
    int mn = *min_element(vf(a));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mn)
            cnt++;
    }
    // dbg(k);
    int ans = cnt + 1 + (mn * n) - n;
    cout << ans << endl;
    dbg(a);
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