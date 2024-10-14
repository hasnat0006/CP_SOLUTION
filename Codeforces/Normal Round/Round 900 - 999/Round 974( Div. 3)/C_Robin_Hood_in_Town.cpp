//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|09|2024 21:08:06            !//
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(vf(a));
    if (n <= 2) {
        cout << -1 << endl;
        return;
    }
    int sum = accumulate(vf(a), 0ll);
    int midVal = a[n / 2];
    int per = midVal * 2;
    int add = per * n + 1;
    float avg = (float)add / (1.0 * n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > avg)
            cnt++;
        if (cnt > n / 2) {
            cout << 0 << endl;
            return;
        }
    }
    if (add > sum) {
        cout << add - sum << endl;
    }
    else
        cout << 0 << endl;
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