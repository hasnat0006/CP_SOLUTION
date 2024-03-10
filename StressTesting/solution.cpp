//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 20:26:26            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int x, y, g;
    cin >> x >> y >> g;
    int upA = (x * (x + 1)) / 2;
    int UP = upA * g;
    int DOWN = (int) 1e9;
    int gcd = __gcd(UP, DOWN);
    UP /= gcd, DOWN /= gcd;
    cout << UP << "/" << DOWN << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;;;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}