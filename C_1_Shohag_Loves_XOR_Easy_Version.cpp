//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|11|2024 21:11:30            !//
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
    ll x, m;
    cin >> x >> m;
    ll base = log2(x);
    ll from = 1LL << base;
    ll to = 1LL << (base + 1);
    ll ans = 0;
    for(ll i = from; i <= to and i <= m; i++) {
        ll XOR = x ^ i;
        if(!XOR)
            continue;
        if(x % XOR == 0 or i % XOR == 0)
            ans++;
    }
    cout << ans << "\n";
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