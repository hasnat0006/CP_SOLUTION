#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0)),
        pre(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        partial_sum(vf(v[i]), pre[i].begin());
        sum[i] = pre[i].back();
    }
    dbg(pre);

    set<ll> st;
    for (int i = 1; i <= n; i++) {
        ll mn = inf;
        map<ll, set<pair<ll, ll>, greater<pair<ll, ll>>>> mp;
        for (int j = 1; j <= n; j++) {
            ll diff = sum[j] - v[j][i];
            mp[diff].insert({sum[j], j});
            mn = min(mn, diff);
        }
        dbg(mp);
        auto temp = *mp[mn].begin();
        ll id = temp.second;
        dbg(mn, id);
        sum[id] = mn;
    }
    dbg(sum);
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