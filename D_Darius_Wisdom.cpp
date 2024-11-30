//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|11|2024 22:51:09            !//
//!-----------------------------------------------------!//

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
    vector<ll> v(n);
    map<ll, vector<ll>> mp;
    set<ll> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1)
            st.insert(i);
        mp[v[i]].push_back(i);
    }
    dbg(mp);
    ll one = mp[1].size(), zero = mp[0].size(), two = mp[2].size();
    dbg(zero, one, two);
    vector<pair<ll, ll>> ans;

    vector<ll> cp = v;
    sort(vf(cp));
    vector<ll> mark(n, 0);
    for (int i = 0; i < n; i++)
        if (cp[i] == v[i])
            mark[i] = 1;

    ll last = n - 1;
    while (last > 0 and mark[last]) {
            last--;
    }

    for (int i = 0; i < n - two; i++) {
        if (v[i] == 2) {
            auto id = st.lower_bound(n - two - 1);
            if (id == st.end()) {
                id = st.begin();
            }
            ans.push_back({last, *id});
            swap(v[last], v[*id]);
            ans.push_back({i, last});
            swap(v[last], v[i]);
            st.erase(id);
            st.insert(i);
            while (last > 0 and mark[last]) {
                    last--;
            }
        }
    }
    dbg(v);
    vector<ll> temp(vf(st));

    for(auto i : temp) {
        if(v[i] == 1)
            st.erase(st.find(i));
    }

    dbg(v);

    for(ll i = zero; i < n - two; i++) {
        if(v[i] == 0) {
            dbg(i);
            swap(v[i], v[*st.begin()]);
            ans.push_back({i, *st.begin()});
            st.erase(st.begin());
        }   
    }
    dbg(v);
    dbg("----------");
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << min(u, v) + 1 << " " << max(u, v) + 1 << '\n';
    }
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