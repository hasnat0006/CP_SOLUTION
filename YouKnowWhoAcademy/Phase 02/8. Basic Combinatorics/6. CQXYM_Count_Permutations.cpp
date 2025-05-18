//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|01|2025 12:11:14            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

vector<ll> fact((int)2e5 + 5, 1);

void cal() {
    for (int i = 3; i <= 2e5; i++) {
        fact[i] = (fact[i - 1] * i);
        fact[i] %= mod;
    }
}

void solve() {
    ll n;
    cin >> n;
    cout << fact[2 * n] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    cal();
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}