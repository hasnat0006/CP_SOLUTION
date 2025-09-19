#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, tt = 3e6;
    cin >> n;
    vector<vector<ll>> v(n);
    ll N = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        N = max(N, x);
        vector<ll> temp;
        for (int j = 0; j < x; j++) {
            ll y;
            cin >> y;
            temp.push_back(y);
        }
        v[i] = temp;
    }
    vector<pair<ll, ll>> mn(N + 5, {inf, -1});
    sort(vf(v));
    map<tuple<ll, ll, ll>, ll> mp;
    for (int i = 0; i < n; i++) {
        for (int j = v[i].size() - 1; j >= 0; j--) {
            ll y = v[i][j];
            if (y < mn[j].first)
                mn[j] = {y, i};
            else if (y == mn[j].first) {
                ll preId = mn[j].second;
                ll k = j + 1;
                ll f = 0;
                while (k < v[preId].size() and k < v[i].size() and
                       v[preId][k] == v[i][k]) {
                    if (mp.count({i, k, preId})) {
                        mn[j].second = mp[{i, k, preId}];
                        mp[{i, j, preId}] = mp[{i, k, preId}];
                        f = 1;
                        break;
                    }
                    k++;
                }
                if (f)
                    continue;
                if (k < v[preId].size() and k < v[preId].size()) {
                    if (v[preId][k] < v[i][k]) {
                        mn[j].second = preId;
                        mp[{i, j, preId}] = preId;
                    }
                    else {
                        mn[j].second = i;
                        mp[{i, j, preId}] = i;
                    }
                }
                else
                    mp[{i, j, preId}] = preId;
            }
        }
    }
    dbg(mn);
    vector<ll> ans(N);
    ll i = 0;
    while (i < N) {
        auto [curMN, id] = mn[i];
        for (int j = i; j < v[id].size(); j++) {
            ans[i++] = v[id][j];
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << '\n';
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