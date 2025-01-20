//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|12|2024 20:37:44            !//
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
    vector<ll> v;
    ll f = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x > 0 or f) {
            v.push_back(x);
        }
        if (x > 0)
            f = 1;
        // dbg(f, v);
    }
    dbg(v);
    while (v.size() > 0 and v.back() == 0)
        v.pop_back();
    if (v.empty())
        cout << 0 << '\n';
    else {
        for (auto i : v) {
            if (i == 0) {
                cout << 2 << '\n';
                return;
            }
        }
        cout << 1 << '\n';
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