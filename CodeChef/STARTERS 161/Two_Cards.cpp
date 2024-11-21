//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|11|2024 20:33:10            !//
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

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp[i] = {a[i], i};
    }
    sort(vr(temp));
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll id1 = temp[0].second, id2 = temp[1].second;

    for (int i = 0; i < n; i++) {
        ll alice = max(a[i], b[i]), bob;
        if (i == id1) {
            bob = max(a[id2], b[id2]);
        }
        else
            bob = max(a[id1], b[id1]);
        if(alice > bob) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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