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
    ll n;
    cin >> n;
    ll up = 0, down = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x >= up and y >= down)
            up = x, down = y;
        else {
            ll div1 = up / x + (up % x > 0);
            ll div2 = down / y + (down % y > 0);
            up = x * max(div1, div2);
            down = y * max(div1, div2);
        }
    }
    cout << up + down << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}