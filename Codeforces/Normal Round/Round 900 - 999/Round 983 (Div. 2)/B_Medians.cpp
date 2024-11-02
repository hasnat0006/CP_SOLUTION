//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|11|2024 21:31:59            !//
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

void solve() {
    ll n, k;
    cin >> n >> k;
    if(n == 1){
        cout << "1\n1\n";
        return;
    }
    if(k == 1 or k == n){
        cout << -1 << '\n';
        return;
    }
    int right = n - k;
    if(right % 2){
        cout << 3 << '\n';
        cout << 1 << " " << k << " " << k + 1 << '\n';
    }
    else {
        cout << 5 << '\n';
        cout << 1 << " " << 2 << " " << k << " " << k + 1 << " " << k + 2 << '\n';
    }
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