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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n + 1);
    v[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll diff = v[i].first - v[i - 1].first;
        if (diff % 2 == 0 and v[i].second == v[i - 1].second)
            ans += diff;
        else if (diff % 2 == 1 and v[i].second != v[i - 1].second)
            ans += diff;
        else
            ans += (diff - 1);
        dbg(i, ans);
    }
    ans += (m - v.back().first);
    dbg(ans);
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