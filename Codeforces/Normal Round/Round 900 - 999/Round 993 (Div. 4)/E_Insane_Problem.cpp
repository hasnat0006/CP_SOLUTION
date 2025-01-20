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
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ll k = a, l1 = b, r1 = c, l2 = d, r2 = e;
    ll ans = 0;
    ll p = 1, mx = 1e9;

    auto inRange = [&](ll l, ll r) { return (r / p) - (l - 1) / p; };

    while (p <= mx) {
        ll l = p * l1, r = p * r1;
        ans += max(0LL, inRange(max(l, l2), min(r, r2)));
        p *= k;
    }
    cout << ans << '\n';
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