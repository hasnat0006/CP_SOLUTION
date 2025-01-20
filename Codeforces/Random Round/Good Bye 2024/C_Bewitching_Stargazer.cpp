//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    ll n, k;
    cin >> n >> k;
    function<pair<ll, ll>(ll)> findAns = [&](ll r) -> pair<ll, ll> {
        if (r < k)
            return {0, 0};
        ll mid = (r + 1) / 2;
        auto [val, seg] = findAns(r / 2);
        if (r % 2) {
            ll ans = mid + 2 * val + (mid * seg);
            return {ans, 2 * seg + 1};
        }
        else {
            ll ans = 2 * val + mid * seg;
            return {ans, 2 * seg};
        }
    };

    cout << findAns(n).first << '\n';
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