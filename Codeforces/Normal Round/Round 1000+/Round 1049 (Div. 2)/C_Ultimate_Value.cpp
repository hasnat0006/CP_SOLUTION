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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = 0;
    vector<pair<ll, ll>> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            ans -= v[i];
            even.push_back({v[i], i});
        }
        else {
            ans += v[i];
            odd.push_back({v[i], i});
        }
    }

    dbg(ans);

    sort(vf(odd));
    sort(vr(even));

    dbg(odd);
    dbg(even);

    ll ans1 = ans + (n % 2 ? n : n - 1) - 1;
    ll ans2 = -inf;
    for (int o = 0; o < odd.size(); o++) {
        for (int i = o; i < even.size(); i++) {
            ll temp = abs(odd[o].second - even[i].second) +
                      2LL * (even[i].first - odd[o].first);
            ans2 = max(ans2, ans + temp);
            dbg(o, i, temp, ans2);
        }
    }
    dbg(ans1, ans2);
    cout << max({ans1, ans2}) << '\n';
    dbg("------------");
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
