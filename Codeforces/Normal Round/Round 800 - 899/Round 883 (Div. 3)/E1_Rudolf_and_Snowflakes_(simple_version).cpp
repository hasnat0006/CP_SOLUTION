//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 00:23:43            !//
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

int mod = 1000000007;
int inf = 1e18;

set<int> st;
void preCal() {
    for (int i = 2; i <= 1000; i++) {
        int k = 1 + i;
        int kk = i * i;
        for (int j = 2; j <= 20; j++) {
            k += kk;
            if (k > (int)1e6)
                break;
            // dbg(k);
            st.insert(k);
            kk *= i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    (st.find(n) != st.end()) ? cout << "YES" << endl : cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    preCal();
    dbg(st);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}