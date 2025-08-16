//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|08|2025 08:56:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "123\n456\n789\n";
    }
    else if (n == 1) {
        cout << "12*\n345\n678\n";
    }
    else if (n == 2) {
        cout << "12*\n34*\n567\n";
    }
    else if (n == 3) {
        cout << "12*\n34*\n56*\n";
    }
    else if (n == 4) {
        cout << "**1\n*23\n*45\n";
    }
    else if (n == 5) {
        cout << "1*2\n34*\n***\n";
    }
    else if (n == 6) {
        cout << "***\n*1*\n2*3\n";
    }
    else if (n == 7) {
        cout << "12*\n***\n***\n";
    }
    else if (n == 8) {
        cout << "1**\n***\n***\n";
    }
    else
        cout << "***\n***\n***\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}