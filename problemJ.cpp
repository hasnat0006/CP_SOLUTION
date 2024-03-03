//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 22:57:02            !//
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

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}


int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}

void solve() {
    int n;
    cin >> n;
    int cur = 1;
    int extra = 1;
    for (int i = 2; i < n; i++) {
        cur = mod_mul(cur, 2);
        cur = mod_add(cur, extra);
        extra = mod_mul(extra, 2);
    }
    cout << cur << endl;
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