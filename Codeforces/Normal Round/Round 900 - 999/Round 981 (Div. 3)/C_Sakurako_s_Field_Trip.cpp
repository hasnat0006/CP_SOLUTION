//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 21:47:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (ll i = (n / 2) - 1; i >= 0; i--) {
        // left er sathe somosha
        if (v[i] == v[n - i - 1])
            continue;
        ll somosha = 0;
        if (v[i] == v[i + 1]) {
            somosha++;
        }
        if (v[n - i - 1] == v[n - i - 2]) {
            somosha++;
        }
        if (somosha > 0)
            swap(v[i], v[n - i - 1]);
    }
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1])
            ans++;
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