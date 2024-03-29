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
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int unlock_assignments = 1 + (n - 1) / 7;
    dbg(unlock_assignments);
    int high = n, low = 0, ans = n;
    while (low <= high) {
        int possibleDays = (high + low + 1) / 2;
        dbg(low, high, possibleDays);
        int perDayPoints = l + t;
        int remainingAssignments = unlock_assignments - possibleDays;
        int points =
            l * possibleDays + min(unlock_assignments, possibleDays) * t;
        dbg(points);
        if (remainingAssignments > 0)
            points += min(remainingAssignments, possibleDays) * t;
        if (points >= p) {
            ans = min(ans, possibleDays);
            high = possibleDays - 1;
        }
        else
            low = possibleDays + 1;
        dbg(ans, points);
    }
    cout << n - ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        dbg(i, "-----------");
        solve();
    }
    return 0;
}