//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 12:10:04            !//
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

int binaryExp(__int128_t base, __int128_t power, __int128_t MOD = mod) {
    __int128_t res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}
int mminvprime(__int128_t a, __int128_t b) { return binaryExp(a, b - 2, b); }
int mod_mul(int a, int b, int MOD = mod) {
    __int128_t A = a % MOD, B = b % MOD;
    return (((A * B) % MOD) + MOD) % MOD;
}
int mod_div(__int128_t a, __int128_t b, __int128_t MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}

void solve() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << binaryExp(a, b, p) << endl;
    cout << mod_mul(a, b, p) << endl;
    cout << mod_div(a, b, p) << endl;
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