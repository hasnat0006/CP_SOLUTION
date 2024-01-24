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
    int n;
    cin >> n;
    int sq = sqrt(n);
    int sq1 = (sq * sq == n) ? sq : sq + 1;
    if (sq == sq1)
        (sq % 2 == 0) ? cout << sq << " " << 1 << endl : cout << 1 << " " << sq << endl;
    else{
        int rem = n - (sq * sq);
        if(sq1 % 2 == 0)
            (rem <= sq1) ? cout << rem << " " << sq1 << endl : cout << sq1 << " " << sq1 - (rem - sq1)  << endl;
        else
            (rem <= sq1) ? cout << sq1 << " " << rem << endl : cout << sq1 - (rem - sq1) << " " << sq1 << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}