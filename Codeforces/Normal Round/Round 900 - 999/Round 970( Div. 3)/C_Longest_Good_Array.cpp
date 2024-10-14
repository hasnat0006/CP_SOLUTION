//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 21:07:25            !//
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

vector<int> v(45000);

void solve() {
    int l, r;
    cin >> l >> r;
    int m = l - 1;
    l -= m, r -= m;
    int id = upper_bound(v.begin(), v.end(), r) - v.begin();
    dbg(id);
    cout << id - 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    v[0] = 1;
    int c = 0;
    for (int i = 1; i < 45000; i++) {
        v[i] = v[i - 1] + c;
        // dbg(i, c, v[i]);
        c++;
    }
    // dbg(v);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}