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
    ll n, m;
    cin >> n >> m;
    ll mx = m + n + 5;
    map<ll, ll> mp; set<pair<ll, ll>> st;
    for(int i = n; i > 0; i--) {
        st.insert({mx, i});
        mp[i] = mx--;
    }
    map<ll, ll> ans;
    for(int i = 0; i < m; i++) {
        dbg(st);
        ll x; cin >> x;
        if(mp.count(x)) {
            ll preMX = mp[x];
            dbg(x, preMX);
            st.erase(st.find({preMX, x}));
            st.insert({mx, x});
            mp[x] = mx;
        }
        else {
            mp[x] = mx;
            st.insert({mx, x});
            auto it = st.end();
            it--;
            mp.erase((*it).second);
            ans[(*it).second] = i + 1;
            st.erase(it);
        }
        mx--;
        dbg(st);
        dbg(mp);
    }
    dbg(ans);
    for(int i = 1; i <= n; i++) {
        cout << (ans.count(i) ? ans[i] : -1) << " ";
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