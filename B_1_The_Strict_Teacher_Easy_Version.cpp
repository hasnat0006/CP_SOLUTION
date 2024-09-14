//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|09|2024 21:10:38            !//
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    while (q--) {
        int pos;
        cin >> pos;
        int idPos = lower_bound(vf(v), pos) - v.begin();
        int f = 0;
        int leftParbo = 0, rightParbo = 0;
        if (idPos == 0) {
            leftParbo = max(0ll, pos - 1);
            rightParbo = max(0ll, v[idPos] - pos - 1);
            f = 1;
        }
        else if (idPos == m) {
            leftParbo = max(0ll, pos - v[idPos - 1] - 1);
            rightParbo = max(0ll, n - pos);
            f = 1;
        }
        else {
            leftParbo = max(0ll, pos - v[idPos - 1] - 1);
            rightParbo = max(0ll, v[idPos] - pos - 1);
        }
        dbg(idPos, leftParbo, rightParbo);
        if (f) {
            cout << leftParbo + rightParbo + 1 << endl;
        }
        else {
            cout << ((leftParbo + rightParbo) / 2) + 1 << endl;
        }
    }
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