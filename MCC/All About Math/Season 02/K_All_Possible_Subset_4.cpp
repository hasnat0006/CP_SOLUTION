//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 12:34:30            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll   long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  
        cin >> v[i];
    
    function<ll(ll, ll)> findAns = [&] (ll i, ll mask) -> ll {
        if(i < 0) {
            ll mx = 0, mn = inf, sum = 0;
            for(int id = 0; id < n; id++) {
                if(mask & (1LL << id)) {
                    mx = max(mx, v[id]);
                    mn = min(mn, v[id]);
                    sum += v[id];
                }
            }
            return (sum <= r and sum >= l and abs(mn - mx) >= x);
        }

        return findAns(i - 1, mask) + findAns(i - 1, mask | (1 << i));
    };

    cout << findAns(n - 1, 0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    //cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}