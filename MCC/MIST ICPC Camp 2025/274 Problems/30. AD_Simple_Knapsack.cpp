#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    map<pair<ll, ll>, ll> mp;
    function<ll(ll, ll)> KNAPSACK = [&](ll i, ll wt) {
        if (i == n or wt == 0)
            return 0LL;
        if (mp.count({i, wt}))
            return mp[{i, wt}];
        ll nibo = 0;
        ll nibona = KNAPSACK(i + 1, wt);
        if (wt - v[i].first >= 0)
            nibo = v[i].second + KNAPSACK(i + 1, wt - v[i].first);
        return mp[{i, wt}] = max(nibo, nibona);
    };

    cout << KNAPSACK(0, w) << '\n';
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