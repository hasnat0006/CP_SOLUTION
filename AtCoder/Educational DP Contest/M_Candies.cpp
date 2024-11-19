//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 12:31:09            !//
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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> prefix(k + 5, 0);
    vector<ll> temp(k + 5, 0);
    for (ll i = 0; i < n; i++) {
        for (ll left = 0; left <= k; left++) {
            if (i == 0)
                temp[left] = (left <= v[i]);
            else {
                ll r = left, l = left - v[i] - 1;
                temp[r] = (prefix[r] - (l >= 0 ? prefix[l] : 0) + mod) % mod;
            }
        }
        prefix[0] = temp[0];
        prefix[0] %= mod;
        for(ll i = 1; i <= k; i++)
            prefix[i] = (prefix[i - 1] + temp[i]) % mod;
    }

    cout << temp[k] % mod << '\n';
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