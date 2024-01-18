//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
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
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve() {
    
    int n, m;
    cin >> n >> m;
    int e = abs(n - m);
    int sq = sqrt(8 * e);
    int v = (sq + 1) / 2;
    dbg(sq, v);
    if (e % 2 == 1) {
        if (v % 4 == 0)
            cout << v + 1 << endl;
        else if (v % 4 == 1 || v % 4 == 2)
            cout << v << endl;
        else
            cout << v + 2 << endl;
    }
    else {
        if (v % 4 == 2)
            cout << v + 1 << endl;
        else if (v % 4 == 3 || v % 4 == 0)
            cout << v << endl;
        else
            cout << v + 2 << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // dbg(i, "-----------");
        solve();
    }
    return 0;
}