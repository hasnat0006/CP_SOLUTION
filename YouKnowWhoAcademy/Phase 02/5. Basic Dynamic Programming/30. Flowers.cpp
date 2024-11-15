//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|11|2024 16:18:44            !//
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

class SEGMENT_TREE {
   public:
    vector<ll> v;
    vector<ll> seg;
    SEGMENT_TREE(ll n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array),
    //! (ql & qr) = user input in 1 based indexing;
    ll find(ll ti, ll tl, ll tr, ll ql, ll qr) {
        if (tl > qr || tr < ql) {
            return 0;
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        ll mid = (tl + tr) / 2;
        ll l = find(2 * ti, tl, mid, ql, qr);
        ll r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return max(l, r);
    }
    //! intially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
    //! user input in 1 based indexing, val = updated value;
    void update(ll ti, ll tl, ll tr, ll id, ll val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti] = val;
            return;
        }
        ll mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = max(seg[2 * ti], seg[2 * ti + 1]);
    }
    // use 1 based indexing for input and queries and update;
};

void solve() {
    ll n;
    cin >> n;
    SEGMENT_TREE s(n);
    vector<ll> height(n + 5), beauty(n + 5), dp(n + 5);
    for (ll i = 1; i <= n; i++) {
        cin >> height[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> beauty[i];
    }
    dbgc(height);
    dbgc(beauty);
    for (ll i = 1; i <= n; i++) {
        ll temp = beauty[i];
        // for (ll j = 1; j < i; j++) {
        //     if (height[i] > height[j]) {
        //         temp = max(temp, dp[j] + beauty[i]);
        //     }
        // }
        dp[i] = temp;
        // optime using segment tree
        if(height[i] != 1){
            ll mx = s.find(1, 1, n, 1, height[i]);
            dbgc(mx);
            dp[i] = max(dp[i], mx + beauty[i]);
        }
        dbgc(i, dp[i]);
        s.update(1, 1, n, height[i], dp[i]);
    }
    dbgc(dp);
    cout << *max_element(vf(dp)) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}