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
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll alice = 0, bob = 0;
    vector<pair<ll, ll>> cnt;
    for (auto [x, c] : mp) {
        cnt.push_back({c, x});
    }

    auto cmp = [](pair<ll, ll> a, pair<ll, ll> b) {
        ll ta = a.second / 2;
        ta *= a.first;
        if(a.second % 2)
            ta += a.first;
        ll tb = b.second / 2;
        tb *= b.first;
        if(b.second % 2)
            tb += b.first;
        dbg(ta, tb);
        if(ta == tb)
            return a.first < b.first;
        return ta < tb;
    };

    sort(vr(cnt), cmp);
    dbg(cnt);
    for (int i = 0; i < cnt.size(); i++) {
        ll take = cnt[i].second / 2;
        alice += (cnt[i].first * take);
        bob += (cnt[i].first * take);
        if (cnt[i].second % 2) {
            if (i % 2)
                bob += cnt[i].first;
            else
                alice += cnt[i].first;
        }
    }
    cout << alice << " " << bob << '\n';
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