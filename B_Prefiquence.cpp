//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|05|2024 20:50:44            !//
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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0, j = 0; i < n and j < m; i++) {
        if (s1[i] == s2[j]) {
            ans++;
            j++;
        }
        else {
            while (j < m and s1[i] != s2[j]) {
                dbg(i, j);
                j++;
            }
            if (j < m and s1[i] == s2[j]) {
                ans++;
                j++;
            }
        }
        if (j == m)
            break;
        dbg(i + 1, j, ans);
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