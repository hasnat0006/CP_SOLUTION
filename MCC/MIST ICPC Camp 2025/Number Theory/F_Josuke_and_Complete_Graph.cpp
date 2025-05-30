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
    ll l, r;
    cin >> l >> r;
    auto findAns = [&](ll rL, ll rR, ll q) {
        ll low = rL, high = min(rR, l);
        while (low < high) {
            ll mid = (low + high + 1) / 2;
            dbg(low, high, mid);
            if (mid * q <= r)
                low = mid;
            else
                high = mid - 1;
        }
        dbg(low, rL, rR);

        return low == l + 1 ? low - rL : low - rL + 1;
    };

    ll ans = max(0LL, (r / 2) - l + 1), g = 1;
    l--;
    while (g <= l) {
        ll b = (l) / g + 2;
        ll next = (l / (l / g));
        dbg(g, b, next, ans);
        if (b * g <= r)
            ans += findAns(g, next, b);
        g = next + 1;
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