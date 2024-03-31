//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 03:04:54            !//
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

vector<int> v;
int dp[505][62700];

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
int mminvprime(int a, int b) { return binaryExp(a, b - 2, b); }
int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}
int mod_div(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}  // only for prime MOD

int findAns(int id, int k) {
    if (k == 0)
        return 1;
    if (id < 0)
        return 0;
    if (dp[id][k] != -1)
        return dp[id][k];
    int notTake = findAns(id - 1, k), take = 0;
    if (k - v[id] >= 0)
        take = findAns(id - 1, k - v[id]);
    return dp[id][k] = (take + notTake) % mod;
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 1; i <= n; i++)
        v[i] = i;
    memset(dp, -1, sizeof(dp));
    int total = (n * (n + 1)) / 2;
    if (total % 2) {
        cout << 0 << endl;
        return;
    }
    int ans = findAns(n, total / 2);
    cout << mod_div(ans, 2) << endl;
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