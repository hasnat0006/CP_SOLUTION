//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    map<ll, ll> mp, id;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= q;
        mp[v[i]]++;
        id[v[i]] = i + 1;
    }
    for (auto [i, c] : mp) {
        if (c == 1) {
            cout << "YES\n" << id[i] << '\n';
            return;
        }
    }
    cout << "NO\n";
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