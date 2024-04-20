//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|04|2024 18:12:27            !//
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
    vector<int> v(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]] = i;
    }
    dbg(v);
    int ans = 0;
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            p.push_back({i, mp[i]});
            ans++;
            swap(v[i], v[mp[i]]);
            mp[v[mp[i]]] = mp[i];
        }

        dbg(v);
    }
    cout << ans << endl;
    for (auto i : p) {
        cout << i.first << " " << i.second << endl;
    }
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