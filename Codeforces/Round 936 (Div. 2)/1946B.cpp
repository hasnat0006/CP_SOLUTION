//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|03|2024 20:47:48            !//
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

int maxSubArraySum(vector<int> &a) {
    int size = a.size();
    int maxTill = -LLONG_MAX, maxEnd = 0;
    for (int i = 0; i < size; i++) {
        maxEnd = maxEnd + a[i];
        if (maxTill < maxEnd)
            maxTill = maxEnd;
        if (maxEnd < 0)
            maxEnd = 0;
    }
    return maxTill;
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

int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maxSum = maxSubArraySum(v);
    if (maxSum < 0) {
        cout << (mod + (accumulate(v.begin(), v.end(), 0ll) % mod)) % mod << endl;
        return;
    }
    // cout << maxSum << endl;
    int ans = accumulate(v.begin(), v.end(), 0ll);
    ans = ans % mod;
    ans = (ans + (mod_mul(maxSum, (binaryExp(2, k) - 1)))) % mod;
    if (ans < 0) {
        cout << (mod + (ans % mod) % mod) << endl;
    }
    else
        cout << ans % mod << endl;
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