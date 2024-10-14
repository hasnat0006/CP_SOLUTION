//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 21:57:49            !//
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

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = s;
    reverse(vf(ss));
    set<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.insert(i);
            div.insert(n / i);
        }
    }
    int ans = n;
    for (auto k : div) {
        int mismatch1 = 0, mismatch2 = 0;
        for (int i = k; i < n; i++) {
            if (s[i] != s[i % k])
                mismatch1++;
            if (ss[i] != ss[i % k])
                mismatch2++;
            if (mismatch1 > 1 and mismatch2 > 1)
                break;
        }
        if (mismatch1 <= 1 or mismatch2 <= 1) {
            ans = min(ans, k);
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