//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|11|2024 19:20:08            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll mxk(ll n) {
    ll k = 0;
    ll sum = 0;
    while (sum + (k + 1) <= n) {
        k++;
        sum += k;
    }
    return k;
}
void solve() {
    ll w, b;
    cin >> w >> b;
    ll sm = w + b;
    ll total = mxk(sm);
    cout << total << "\n";
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}