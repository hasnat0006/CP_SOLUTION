//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|10|2024 21:57:12            !//
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
    string s;
    cin >> s;
    s = "0" + s;
    int ans = 0;
    while (s != "1" and s != "01") {
        if (s.back() == '1') {
            int n = s.size();
            n--;
            while (s[n] != '0') {
                n--;
            }
            for (int i = n; i < s.size(); i++) {
                s[i] = (s[i] == '0' ? '1' : '0');
            }
            ans++;
        }
        ans++;
        s.pop_back();
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}