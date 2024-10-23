//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|10|2024 21:59:24            !//
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
    for (ll &i : v)
        cin >> i;
    ll mx = *max_element(v.begin() + 1, v.end());
    ll mn = *min_element(v.begin() + 1, v.end());
    auto find_id = [&](ll x) {
        for (ll i = n - 1; i > 0; i--) {
            if (v[i] == x)
                return i;
        }
    };
    ll mn_id = find_id(mn);
    ll mx_id = find_id(mx);
    if (v.front() > mx) {
        cout << -1 << '\n';
        return;
    }
    if (mx_id < mn_id) {
        if (v.front() >= mn) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << n - 2 << '\n';
    ll cnt = n - 3;
    while (cnt--) {
        cout << 2 << " " << 4 << '\n';
    }
    cout << 1 << " " << 3 << '\n';
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