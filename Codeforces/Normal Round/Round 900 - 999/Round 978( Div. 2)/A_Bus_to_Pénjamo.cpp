//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 01:38:00            !//
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
    int n, seat;
    cin >> n >> seat;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int happyRow = 0;
    for (int i = 0; i < n; i++) {
        happyRow += (v[i]) / 2;
        v[i] %= 2;
    }
    int rem = seat - happyRow;
    dbg(happyRow, rem);
    int ans = happyRow * 2;
    int sum = accumulate(vf(v), 0LL);
    dbg(sum);
    for (int i = 0; (i < n and rem > 0); i++) {
        if (v[i] > 0 and (rem - 1) * 2 >= (sum - 1)) {
            rem--;
            ans++;
            sum--;
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