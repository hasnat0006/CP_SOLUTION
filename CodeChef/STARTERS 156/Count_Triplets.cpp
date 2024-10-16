//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|10|2024 21:26:56            !//
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int k = i + 1; (k < n and cnt <= 100); k++, cnt++) {
            int diff = abs(v[i] - v[k]);
            int idDiff = abs(i - k);
            if (diff == idDiff) {
                ans += 2;
                ans += (diff - 1);
            }
            int bakiDiff = diff - idDiff;
            dbg(ans);
            dbg(i, k, diff, idDiff, bakiDiff);
            if (bakiDiff > 0 and bakiDiff % 2 == 0) {
                int lagbe = bakiDiff / 2;
                int left = i, right = n - (k + 1);
                dbg(left, right, lagbe);
                if (left >= lagbe)
                    ans++;
                if (right >= lagbe)
                    ans++;
            }
            dbg(ans);
        }
    }
    ans *= 2;
    ans += n;
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