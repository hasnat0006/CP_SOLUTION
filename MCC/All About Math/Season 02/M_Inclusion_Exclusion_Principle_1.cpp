//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 14:34:01            !//
//!-----------------------------------------------------!//

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
    vector<ll> v = {2, 3, 5, 7};
    ll ans = 0;

    function<ll(ll, ll)> findAns = [&](ll i, ll mask) -> ll {
        if (i < 0) {
            ll cnt = 0, num = 1;
            for (int m = 0; m < 4; m++) {
                if (mask & (1 << m))
                    cnt++, num *= v[m];
            }
            return (cnt % 2 ? -(n / num) : (n / num));
        }
        return findAns(i - 1, mask) + findAns(i - 1, mask | (1 << i));
    };

    cout << findAns(3, 0) << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}