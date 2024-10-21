//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|10|2024 15:21:49            !//
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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(vf(v));
    int komse = 0, extraMove = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int pabo = (v[i] - komse) * (n - i);
        if (pabo <= 0) {
            extraMove++;
            continue;
        }
        cnt += pabo;
        if (cnt >= k) {
            cout << k + extraMove << endl;
            return;
        }
        int temp = v[i] - komse;
        komse += temp;
        extraMove++;
        dbg(i, cnt, pabo, komse, extraMove);
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