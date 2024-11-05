//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|11|2024 15:34:12            !//
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
    int n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    ll num = 0;
    vector<ll> v;
    while (mp.count(num) > 0) {
        for (int i = 0; i < mp[num]; i++)
            v.push_back(num);
        num++;
    }
    dbgc(v);
    if (v.size() == 0) {
        cout << 0 << '\n';
        return;
    }
    mp.clear();
    map<ll, ll> id;
    for (int i = 0; i < v.size(); i++) {
        id[v[i]] = i;
        mp[v[i]]++;
    }
    dbg(mp);
    vector<ll> cost((int)v.size());
    cost[0] = v[0];
    ll pre = v[0], temp = 1;
    for (int i = 1; i < v.size(); i++) {
        cost[i] = temp;
        if (v[i] != pre)
            temp++, pre = v[i];
    }
    dbgc(cost);
    vector<ll> prefix_cost((int)v.size());
    partial_sum(vf(cost), prefix_cost.begin());
    dbgc(prefix_cost);
    ll ans = inf;
    for (auto i : mp) {
        int index_of_i = id[i.first - 1];
        dbg(index_of_i);
        ll temp_cost = prefix_cost[max(index_of_i, 0)];
        dbg(temp_cost);
        temp_cost = temp_cost + ((v.back() + 1) * (i.second - 1)) + i.first;
        ans = min(ans, temp_cost);
        dbgc(i.first, temp_cost);
    }
    cout << ans << '\n';
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