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
    ll l, r;
    cin >> l >> r;
    if (l * 2 <= r) {
        cout << l * 2 << '\n';
        return;
    }

    ll ans = inf, g = 1;
    l--;
    while (g <= l) {
        ll a = (l) / g + 1;
        ll b = (l) / g + 2;
        dbg(g, a, b);
        if (b * g <= r)
            ans = min(ans, g * a * b);
        g = (l / (l / g)) + 1;
        dbg(ans, g);
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