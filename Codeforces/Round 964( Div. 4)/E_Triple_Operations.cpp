//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|08|2024 22:26:20            !//
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
    int l, r;
    cin >> l >> r;
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < 13; i++) {
        v.push_back(v.back() * 3);
    }
    int ans = 0;
    int id = upper_bound(vf(v), l) - v.begin();
    ans += (id) * 2;
    dbg(id);
    for (int i = id; i < 13; i++) {
        int R = v[i];
        if(R > r)
            R = r ;
        else
            R = R - 1;
        int cnt = R - l;
        l = v[i] - 1;
        ans += cnt * id;
        id++;
        dbg(l, cnt, ans, id);
        if (l >= r)
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