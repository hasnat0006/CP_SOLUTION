#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 998244353;
const ll inf = 1e18;

ll mod_add(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}
ll binaryExp(ll base, ll power, ll MOD = mod) {
    ll res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return binaryExp(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}
ll mod_div(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}  // only for prime MOD

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int p = 0; p < 2; p++) {
            if (dp[i - 1][p] == 0)
                continue;
            ll preA, preB;
            if (i == 1)
                preA = preB = -inf;
            else {
                preA = (p == 0 ? a[i - 2] : b[i - 2]);
                preB = (p == 0 ? b[i - 2] : a[i - 2]);
            }
            if (a[i - 1] >= preA && b[i - 1] >= preB)
                dp[i][0] = mod_add(dp[i][0], dp[i - 1][p]);
            if (b[i - 1] >= preA && a[i - 1] >= preB)
                dp[i][1] = mod_add(dp[i][1], dp[i - 1][p]);
        }
    }
    cout << mod_div(mod_add(dp[n][0], dp[n][1]), 2) << '\n';
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