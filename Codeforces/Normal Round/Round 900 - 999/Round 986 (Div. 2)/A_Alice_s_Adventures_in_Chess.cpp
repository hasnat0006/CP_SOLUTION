//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|11|2024 23:53:08            !//
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll x = 0, y = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 1000; i++) {
        for (auto it : s) {
            if (it == 'N')
                y++;
            else if (it == 'E')
                x++;
            else if (it == 'S')
                y--;
            else
                x--;
            if (x == a and y == b) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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