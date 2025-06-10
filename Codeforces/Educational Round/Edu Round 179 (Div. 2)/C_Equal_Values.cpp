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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<ll, pair<ll, ll>>> conRange;
    ll ans = inf, firstId = 1;
    for (ll i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            conRange.push_back({v[i - 1], {firstId, i}});
            firstId = i + 1;
        }
    }
    if (firstId <= n) {
        conRange.push_back({v[n - 1], {firstId, n}});
    }
    dbg(conRange);
    for (auto [l, r] : conRange) {
        ans = min(ans, (l * (r.first - 1)) + (l * (n - r.second)));
        dbg(ans, l, r.first, r.second);
    }
    cout << ans << endl;
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