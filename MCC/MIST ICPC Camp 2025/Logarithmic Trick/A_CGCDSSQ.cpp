#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    map<ll, ll> cnt[n + 1];
    for (int i = 1; i <= n; i++) {
        cnt[i][v[i]] = 1;
        for (auto [g, f] : cnt[i - 1])
            cnt[i][gcd(v[i], g)] += f;
    }

    map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        for (auto [g, f] : cnt[i])
            mp[g] += f;
    }
    ll m;
    cin >> m;
    while (m--) {
        ll x;
        cin >> x;
        cout << mp[x] << '\n';
    }
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