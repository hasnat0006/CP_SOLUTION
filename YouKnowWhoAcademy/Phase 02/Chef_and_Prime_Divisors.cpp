//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 23:47:34            !//
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

int factors(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a <= sqrt(n); a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int gcd = __gcd(a, b);
    cout << (gcd == 1 ? "No" : "Yes") << endl;
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