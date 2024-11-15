//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|11|2024 15:33:42            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e7 + 5;
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

ll counting(ll n) {
    ll cnt = 1;
    while (n > 1) {
        int r = spf[n];
        ll tempCnt = 0;
        while(n % r == 0)
            tempCnt++, n /= r;
        cnt *= (2 * tempCnt + 1);
    }
    return cnt;
}
map<ll, vector<ll>> mp;
void preCalculate() {
    for (ll i = 1; i * i <= (ll)1e10; i++) {
        mp[counting(i)].push_back(i * i);
    }
}

void solve() {
    ll k, low, high;
    cin >> k >> low >> high;
    cout << upper_bound(vf(mp[k]), high) - lower_bound(vf(mp[k]), low) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    smallestPrimeFactorUsingSeive();
    preCalculate();
    // dbgc(mp);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}