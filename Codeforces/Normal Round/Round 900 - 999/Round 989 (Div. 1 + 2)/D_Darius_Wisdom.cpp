//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|11|2024 22:51:09            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, set<ll>> mp;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]].insert(i);
    }
    vector<ll> copy = v;
    sort(vf(copy));
    vector<pair<ll, ll>> ans;
    for (ll i = 0; i < mp[0].size(); i++) {
        if (v[i] == copy[i])
            continue;
        if (v[i] == 1) {
            ll last0 = *mp[0].rbegin();
            swap(v[i], v[last0]);
            mp[0].erase(mp[0].find(last0));
            mp[1].erase(mp[1].find(i));
            mp[1].insert(last0);
            mp[0].insert(i);
            ans.push_back({i, last0});
        }
        else {
            // last 1 er sathe current 2 swap korbo
            // then 1 er sathe last zero swap korbo
            ll last1 = *mp[1].rbegin();
            ll last0 = *mp[0].rbegin();
            mp[1].erase(mp[1].find(last1));
            mp[0].erase(mp[0].find(last0));
            mp[2].erase(mp[2].find(i));
            swap(v[last1], v[i]);
            swap(v[i], v[last0]);
            mp[0].insert(i);
            mp[1].insert(last0);
            mp[2].insert(last1);
            ans.push_back({i, last1});
            ans.push_back({i, last0});
        }
    }
    for (ll i = mp[0].size(); i < mp[0].size() + mp[1].size(); i++) {
        if (v[i] != copy[i]) {
            ll last1 = *mp[1].rbegin();
            mp[1].erase(mp[1].find(last1));
            mp[2].erase(mp[2].find(i));
            swap(v[i], v[last1]);
            mp[1].insert(i);
            mp[2].insert(last1);
            ans.push_back({i, last1});
        }
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << ++u << " " << ++v << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}