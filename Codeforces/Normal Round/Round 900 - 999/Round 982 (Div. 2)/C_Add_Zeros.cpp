//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|10|2024 20:52:02            !//
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
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    priority_queue<ll> pq;
    map<ll, vector<ll>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pq.push(v[i]);
        mp[v[i]].push_back(i);
    }
    vector<ll> copy = v;
    ll sz = n + 1;
    sort(vf(v));
    dbg(v);
    dbg(copy);
    dbg(mp);
    for (auto &i : mp) {
        sort(vr(i.second));
    }
    while (1) {
        ll mx = sz - 1, mn = sz - n;
        dbg(mx, mn);
        ll id_right = upper_bound(vf(v), mx) - v.begin();
        ll id_left = lower_bound(vf(v), mn) - v.begin();
        dbg(id_right, id_left);
        if (id_left >= id_right)
            break;
        ll maxi = 0;
        for (int i = id_left; i < id_right; i++) {
            dbg("----", v[i]);
            for (auto id_i : mp[v[i]]) {
                ll id = sz - copy[id_i];
                dbg(id, id_i, copy[id_i], copy[id]);
                if (copy[id] == copy[id_i]) {
                    maxi = max(maxi, id_i - 1);
                }
            }
        }
        dbg(maxi);
        if(maxi <= 0)
            break;
        sz += maxi;
        dbg(sz);
    }
    cout << sz - 1 << '\n';
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