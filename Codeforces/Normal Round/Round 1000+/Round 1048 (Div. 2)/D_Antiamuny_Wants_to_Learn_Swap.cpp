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
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), tuple(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = n - 3; i >= 0; i--) {
        tuple[i] = tuple[i + 1];
        if (v[i] > v[i + 1] and v[i + 1] > v[i + 2] and v[i + 1] - v[i + 2] == 1 and v[i] - v[i + 1] == 1)
            tuple[i]++;
    }
    dbg(tuple);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if(r - l < 2)
            cout << "YES" << '\n';
        else {
            ll c = tuple[l] - tuple[r - 1];
            dbg(l, r , c);
            cout << (c > 0 ? "NO" : "YES") << '\n';
        } 
            
    }
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