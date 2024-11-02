//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|10|2024 22:30:05            !//
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

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> v(n, 0);
    v[0] = (s[0] == '1');
    for (ll i = 1; i < n; i++) {
        v[i] = v[i - 1] + (s[i] == '1');
    }
    ll high = v[n - 1];
    int goo = n / 2;
    dbg(goo);
    dbg(v);
    vector<ll> ans;
    ll baki = n;
    for (ll i = n - 1; i > 0 and goo; i--) {
        if (v[i] != v[i - 1] and baki > 1) {
            goo--;
            baki = min(baki - 2, i + 1 - 2);
            ans.push_back(i + 1);
        }
        dbg(i + 1, goo, baki);
    }
    dbg(ans);
    cout << (n * (n + 1)) / 2 - accumulate(vf(ans), 0LL)<< '\n';
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