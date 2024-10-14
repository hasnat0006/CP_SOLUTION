//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 20:44:33            !//
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
    string s;
    cin >> n >> s;
    int sqrtN = sqrt(n);
    if (sqrtN * sqrtN != n) {
        cout << "NO" << endl;
        return;
    }
    int one = sqrtN * 2 + (sqrtN - 2) * 2;
    int ONE = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            ONE++;
    dbg(s, one, ONE);
    if (ONE != one) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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