//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 11:57:15            !//
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
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (s[i - 1] == '1');
    int ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k)
            ans += mp[a[i] - k];
        mp[a[i]]++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}