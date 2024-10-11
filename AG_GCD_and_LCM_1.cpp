//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|10|2024 21:36:09            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int a, b;
    cin >> a >> b;
    int mul = a * b;
    int ans = 0;
    for (int i = 1; i * i <= mul; i++) {
        if (mul % i == 0) {
            if (__gcd(i, mul / i) == a and
                (i * (mul / i)) / __gcd(i, mul / i) == b) {
                ans++;
            }
        }
    }
    cout << ans * 2LL << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}