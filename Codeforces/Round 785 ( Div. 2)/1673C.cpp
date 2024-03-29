//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|03|2024 00:03:53            !//
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

vector<int> palindrome;
int dp[500][40005];

void countWay() {
    for (int i = 1; i < 500; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 40005; j++) {
            if (palindrome[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - palindrome[i]];
            dp[i][j] %= mod;
        }
    }
}

void preCal() {
    for (int i = 0; i <= 4 * 10000; i++) {
        string s = to_string(i);
        string t = s;
        reverse(vf(t));
        if (s == t)
            palindrome.push_back(i);
    }
    countWay();
}

void solve() {
    int n;
    cin >> n;
    int row = lower_bound(vf(palindrome), n) - palindrome.begin();
    cout << dp[row][n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    preCal();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}