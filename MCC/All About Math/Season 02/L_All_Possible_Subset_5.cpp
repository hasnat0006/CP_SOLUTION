//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 13:28:00            !//
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
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    function<ll(ll, ll)> findAns = [&](ll i, ll mask) -> ll {
        if (i < 0) {
            ll add = 0;
            for (int m = 0; m < n; m++) {
                if (mask & (1LL << m))
                    add += v[m];
            }
            ll notAdd = accumulate(vf(v), 0LL) - add;
            return (add % 360) == (notAdd % 360);
        }
        ll ans = findAns(i - 1, mask) | findAns(i - 1, mask | (1LL << i));
        return ans;
    };

    cout << (findAns(n - 1, 0) ? "YES" : "NO") << '\n';
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