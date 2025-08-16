#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {  
    ll l, r;
    cin >> l >> r;
    
    auto function = [] (ll n) {
        vector<ll> primes = {2, 3, 5, 7};
        ll m = 4;
        ll ans = 0;
        for (ll i = 1; i < (1 << m); i++) {
            ll product = 1;
            ll bits = __builtin_popcount(i);
            for (ll j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    product *= primes[j];
                }
            }
            ll count = n / product;
            if (bits % 2 == 1) {
                ans += count; 
            } else {
                ans -= count;
            }
        }
        return ans;
    };
    ll okh = function(r) - function(l - 1);
    cout << (r - l + 1) - okh << '\n';

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