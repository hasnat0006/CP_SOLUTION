//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|11|2024 21:44:26            !//
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
    set<ll> one;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1)
            one.insert(i);
    }
    for (auto id : one) {
        ll i = id;
        while (i - 2 >= 0 and v[i - 1] == 3 and v[i - 2] == 3)
            v[i - 1] = 1, i--;
        i = id;
        while (i + 2 < n and v[i + 1] == 3 and v[i + 2] == 3)
            v[i + 1] = 1, i++;
    }
    for (ll i = 1; i < n - 1; i++) {
        if (v[i] == 3 and v[i - 1] + v[i + 1] == 4)
            v[i] = 1;
    }
    ll sum = accumulate(vf(v), 0LL);
    cout << sum << endl;
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