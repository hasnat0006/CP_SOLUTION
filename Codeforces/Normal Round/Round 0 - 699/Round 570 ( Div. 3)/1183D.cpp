//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|03|2024 03:12:50            !//
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
    int n, x;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> v;
    for (auto i : mp) {
        v.push_back({i.second, i.first});
    }
    sort(v.rbegin(), v.rend());
    dbg(v);
    int ans = 0, highest = v[0].first;
    for (int i = 0; i < v.size(); i++) {
        int possible = min(highest, v[i].first);
        ans += possible;
        highest = possible - 1;
        if(highest <= 0)
            break;
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