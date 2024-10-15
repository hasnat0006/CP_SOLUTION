//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 00:34:10            !//
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

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}

const int N = 50000 + 5;
int spf[N];

void smallestPrimeFactorUsingSeive() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int num  = i;
        while(num > 1){
            int r = spf[num];
            freq[r]++;
            num /= r;
        }
    }
    int ans = 1;
    for(auto i : freq)
        ans = mod_mul(ans, mod_add(i, 1LL));
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    // precal();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}