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
    int n, a, b;
    cin >> n >> a >> b;
    if (a > n) {
        cout << "No" << endl;
        return;
    }
    int baki = n - a;
    // baki = baki * baki;
    if (baki * baki >= 2 * b)
        cout << "Yes" << endl;
    else if (baki % 2 and (baki * baki - 1) >= 2 * (b - baki))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}