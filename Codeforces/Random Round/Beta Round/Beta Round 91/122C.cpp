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

int next_luck_number(int n) {
    int rem = n % 10;
    if (!rem)
        return 4;
    if (rem == 4)
        return n + 3;
    return next_luck_number(n / 10) * 10 + 4;
}

int lucky_number(int l, int r, int ans) {
    if (l > r)
        return ans;
    int next_lucky_int = next_luck_number(l);
    ans += (min(next_lucky_int, r) - l) * next_lucky_int;
    return lucky_number(next_lucky_int, r, ans);
}

void solve() {
    int l, r;
    cin >> l >> r;
    int lucky = 0;
    while (lucky < l)
        lucky = next_luck_number(lucky);
    cout << ((min(lucky, r) - l + 1) * lucky) + lucky_number(lucky, r, 0) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}