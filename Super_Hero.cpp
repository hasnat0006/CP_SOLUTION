//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|11|2024 20:40:55            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll   long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e6 + 5;
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
    ll n, k;
    cin >> n >> k;
    ll step = log2l(k);
    dbgc(step);
    while(n > 1){
        int x = spf[n];
        step++;
        dbg(x, n);
        if(x == n)
            break;
        n /= x;
    }    
    cout << step << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(); 
    }
    return 0;
}