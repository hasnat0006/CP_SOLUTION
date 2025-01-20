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
    ll n, x, y;
    cin >> n >> x >> y;
    map<ll, ll> mp;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(vf(v));
    ll ans = 0, left = sum - y, right = sum - x;
    dbg(left, right, sum);
    for (int i = 0; i < n; i++) {
        ll newLeft = left - v[i], newRight = right - v[i];
        ll idL = lower_bound(v.begin() + i + 1, v.end(), newLeft) - v.begin();
        ll idR =
            upper_bound(v.begin() + i + 1, v.end(), newRight) - v.begin() - 1;
        dbg(newLeft, newRight, idL, idR);
        if (idR >= idL)
            ans += idR - idL + 1;
        dbg(ans);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        dbg("IN");
        solve();
    }
    return 0;
}