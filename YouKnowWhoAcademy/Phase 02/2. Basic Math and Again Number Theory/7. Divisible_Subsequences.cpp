//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|10|2024 23:55:11            !//
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
    int MOD, n;
    cin >> MOD >> n;
    map<int, int> modValue;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        modValue[sum % MOD]++;
    }
    int ans = 0;
    sum = 0;
    map<int, int> alreadyUsed;
    for (int i = 0; i < n; i++) {
        // dbg(sum, modValue[sum], alreadyUsed[sum]);
        ans += (modValue[sum] - alreadyUsed[sum]);
        sum += v[i];
        sum %= MOD;
        alreadyUsed[sum]++;
        // dbg(ans);
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