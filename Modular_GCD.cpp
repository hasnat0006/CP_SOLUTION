//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|02|2024 16:31:38            !//
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

int binaryExp(int base, int power, int MOD = mod) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    if (a == b) {
        cout << (binaryExp(a, n, mod) + binaryExp(b, n, mod)) % mod << endl;
        return;
    }
    int diff = abs(a - b);
    set<int> factors;
    for (int i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            factors.insert(i);
            factors.insert(diff / i);
        }
    }
    int ans = 1;
    for (auto i : factors) {
        int temp = (binaryExp(a, n, i) + binaryExp(b, n, i)) % i;
        if (temp == 0) {
            ans = max(ans, i);
        }
    }
    cout << ans % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}