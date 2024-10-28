//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|10|2024 20:54:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    if (n == 1 or n == 3) {
        cout << -1 << '\n';
        return;
    }
    if (n % 2 == 0) {
        for (ll i = n - 2; i >= 1; i--)
            cout << 3;
        cout << 66;
        cout << '\n';
    }
    else {
        n -= 4;
        for (ll i = n; i >= 1; i--)
            cout << 3;
        cout << 6366;
        cout << '\n';
    }
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