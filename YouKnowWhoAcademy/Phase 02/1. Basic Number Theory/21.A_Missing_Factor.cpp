//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 12:01:37            !//
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

int factor(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a * a <= n; a += 2) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n, r;
    cin >> n;
    n = sqrtl(n);
    while (n > 1) {
        r = factor(n);
        while (n % r == 0)
            n /= r;
    }
    cout << r << endl;
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