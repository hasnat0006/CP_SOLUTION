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
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(vf(v));
    ll gcd = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first != v.back().first) {
            gcd = __gcd(gcd, v[i].first);
        }
    }
    if (gcd == 0 or gcd == v.back().first) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        vector<ll> ans(n, 1);
        for (int i = 0; i < n; i++) {
            if (v[i].first == v.back().first) {
                ans[v[i].second] = 2;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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