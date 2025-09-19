//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|09|2025 09:37:29            !//
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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    set<vector<ll>> st;
    st.insert(v);
    ll f = 0;
    auto mexArray = [&]() {
        dbg(v);
        ll mex = 0;
        map<ll, ll> cnt;
        for (int i = 0; i < n; i++) {
            if (v[i] == mex)
                mex++;
            cnt[v[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt[v[i]] > 1)
                v[i] = mex;
            if (v[i] > mex)
                v[i] = mex;
        }
        dbg(v);
        if (st.find(v) != st.end()) {
            f++;
        }
        st.insert(v);
    };

    ll turn = min(k, 3LL);
    while (turn--) {
        dbg("here");
        mexArray();
        k--;
    }
    if(k)

    dbg("-----------");
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