//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 22:40:56            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int mod_sub(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a - b) % MOD) + MOD) % MOD;
}

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

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

// required function
int findProductSum(vector<int> &A, int n) {
    dbg(A);
    int tomal = 0;
    for (int i = 0; i < n; i++)
        tomal = mod_add(tomal, A[i]);
    int tomal_square = mod_mul(tomal, tomal);
    int individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum = mod_add(individual_square_sum, mod_mul(A[i], A[i]));
    return mod_div(mod_sub(tomal_square, individual_square_sum), 2);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int SUM = findProductSum(v, n);
    int num = n * (n - 1) / 2;
    dbg(SUM, num);
    int ans = mod_div(SUM, num);
    cout << ans << endl;
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