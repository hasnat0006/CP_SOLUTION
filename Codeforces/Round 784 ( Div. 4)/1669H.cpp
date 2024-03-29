//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 10:56:39            !//
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
    int n, k;
    cin >> n >> k;
    vector<bitset<32>> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = bitset<32>(x);
    }
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 0)
                cnt++;
        }
        if (cnt <= k) {
            for (int j = 0; j < n; j++) {
                v[j][i] = 1;
            }
            k -= cnt;
        }
    }
    // for (auto i : v)
        // cout << i << endl;
    int ans = v[0].to_ullong();
    for (int i = 1; i < n; i++) {
        ans &= v[i].to_ullong();
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