//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 01:15:33            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    int total = n * k;
    vector<int> a(total);
    map<int, vector<int>> mp;
    for (int i = 0; i < total; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<int> calculated;
    map<pair<int, int>, int> value;
    map<int, int> index;
    for (int i = 0; i < total; i++) {
        int x;
        cin >> x;
        index[x] = i;
        for (auto &it : mp[x]) {
            int id = upper_bound(vf(calculated), it) - calculated.begin() - 1;
            if (id < 0) {
                value[{i, it}] = 1;
            }
            else {
                value[{i, it}] =
                    value[{index[calculated[id]], a[calculated[id]]}] + 1;
                dbg(i, it, value[{i, it}]);
                dbg(index[calculated[id]], a[calculated[id]]);
            }
            
        }
        for(auto &it : mp[x]) {
            calculated.push_back(it);
        }
        sort(vf(calculated));
        dbg(calculated);
        dbg(value);
    }
    dbg(value);
    int mx = 0;
    for (auto &it : value) {
        mx = max(mx, it.second);
    }
    cout << mx << '\n';
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