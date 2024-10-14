//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|09|2024 21:22:53            !//
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
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        cnt[v[i]]++;
    }
    int ans = 0;
    dbg(v);
    sort(vf(v));
    // for (int i = 0; i < n; i++) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    for (int i = 1; i < n; i++) {
        if (v[i].first == v[i - 1].first and
            abs(v[i].second - v[i - 1].second) == 1) {
            ans += n - 2;
        }
    }
    dbg(ans);

    for (int i = 0; i < n; i++) {
        int x = v[i].first, y = v[i].second;
        // map<int, int> freq;
        // for (int j = 0; j < mp[!y].size(); j++) {
        //     int val = abs(mp[!y][j] - x);
        //     freq[val]++;
        // }
        // for (auto j : freq) {
        //     if (j.second == 2)
        //         ans++;
        // }

        if (cnt[{x + 1, !y}] and cnt[{x - 1, !y}])
            ans++;
        dbg(i, x, y, ans);
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