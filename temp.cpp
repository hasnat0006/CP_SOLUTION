//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|11|2024 21:34:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll   long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve(ll x, ll m) {
    // ll x, m;
    // cin >> x >> m;
    set<ll> divisor;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divisor.insert(i);
            divisor.insert(x / i);
        }
    }
    for (ll i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            divisor.insert(i);
            divisor.insert(m / i);
        }
    }
    set<ll> ans;
    for (auto div : divisor) {
        ll XOR = x ^ div;
        if (XOR > 0 and XOR <= m)
            ans.insert(XOR);
    }

    cout << ans.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve(5, i); 
    }
    return 0;
}