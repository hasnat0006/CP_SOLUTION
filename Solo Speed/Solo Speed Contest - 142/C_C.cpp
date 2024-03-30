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

void solve(int i) {
    int n;
    cin >> n;
    // n = i;
    if (n < 3) {
        cout << 1 << endl;
        return;
    }
    // n--;
    int pw = log2(n);
    // cout << (1 << pw) << endl;
    if (1 << pw != n)
        pw++;
    int bad = (1 << pw) - n - 1;
    bad = max(0ll, bad);
    int x = (1 << pw);
    int y = (1 << (pw - 1));
    int z = (1 << (pw - 2));
    // cout << x << " " << y << " " << bad << endl;
    dbgc(x, y, bad);
    cout << max(x - y - bad, y - z) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}