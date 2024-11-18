//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|11|2024 20:43:28            !//
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
    ll k;
    cin >> k;
    vector<ll> v(k);
    map<ll, ll> mp;
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll n = k - 2;
    set<ll> divisor;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }
    for (auto i : divisor) {
        int a = i;
        int b = n / i;
        if (a == b) {
            if (mp[a] > 1) {
                cout << a << ' ' << a << '\n';
                return;
            }
        }
        else if (mp[a] and mp[b]) {
            cout << a << " " << b << '\n';
            return;
        }
    }
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