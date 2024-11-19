//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 00:02:39            !//
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
    ll n, b, c;
    cin >> n >> b >> c;
    __int128_t B = b, C = c;
    if ((B + C) == 0 and n > 2) {
        cout << -1 << '\n';
        return;
    }
    if (c >= n) {
        cout << n << '\n';
        return;
    }
    if(b == 0){
        if(c == n - 1 or c == n - 2)
            cout << n - 1 << '\n';
        else if(c >= n)
            cout << n << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    __int128_t temp = n - 1 - c + b;
    ll i = (temp) / b;
    cout << n - i << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}