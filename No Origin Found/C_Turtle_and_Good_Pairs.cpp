//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|08|2024 21:15:04            !//
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
    string s;
    cin >> n >> s;
    map<char, int> mp;
    for (char c : s)
        mp[c]++;
    // dbg(mp);
    vector<pair<int, char>> v;
    for (auto x : mp)
        v.push_back({x.second, x.first});
    sort(vr(v));
    // for (int i = 0; i < v.size(); i++) {
    //     dbg(v);
    //     int cnt = v[i].first;
    //     for (int j = i + 1; j < v.size() and cnt > 0; j++) {
    //         int cntJ = v[j].first;
    //         int x = min(cnt, cntJ);
    //         dbg(cnt, cntJ, x);
    //         cnt -= x;
    //         cntJ -= x;
    //         v[j].first = cntJ;
    //         v[i].first = cnt;
    //         while (x--) {
    //             cout << v[i].second << v[j].second;
    //         }
    //     }
    // }
    // dbg(v);
    // for (auto x : v) {
    //     while (x.first--) {
    //         cout << x.second;
    //     }
    // }

    while (1) {
        int f = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first > 0) {
                f = 1;
                cout << v[i].second;
                v[i].first--;
            }
        }
        if (f == 0)
            break;
    }
    cout << endl;
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