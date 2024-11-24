//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|11|2024 21:04:11            !//
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
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << s[i + 1] << '\n';
            return;
        }
    }
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] != s[i + 1] and s[i] != s[i + 2] and s[i + 1] != s[i + 2]) {
            cout << s[i] << s[i + 1] << s[i + 2] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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