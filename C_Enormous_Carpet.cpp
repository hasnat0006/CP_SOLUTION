//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|10|2024 11:27:47            !//
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

int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}

void solve(int ca) {
    int n, k, a;
    cin >> n >> k >> a;
    if (n == 0 && k == 0 && a == 0)
        exit(0);
    cout << "Case " << ca << ":" << endl;
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        int area = mod_mul(a, binaryExp(k, n, x), x);
        cout << area << (i == c - 1 ? "" : " ");
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1;; i++) {
        solve(i);
    }
    return 0;
}