//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|10|2024 20:47:30            !//
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
    string s;
    ll n;
    cin >> n >> s;
    ll zero = 0, one = 0;
    for (ll i = 0; s[i]; i++)
        s[i] == '0' ? zero++ : one++;
    if (one == 0) {
        // only zero ache
        cout << n << '\n';
    }
    else {
        // only one ache
        cout << one % 2 << '\n';
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