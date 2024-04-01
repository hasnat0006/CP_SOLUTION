//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|04|2024 03:21:55            !//
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

// #define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

int dp[1000005];

int findAns(int k) {
    if (k == 0)
        return 0;
    if (dp[k] != -1)
        return dp[k];
    string s = to_string(k);
    set<int> st;
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i] - '0');
    if (*st.begin() == 0)
        st.erase(st.begin());
    int ans = INT_MAX;
    for (auto i : st) {
        if (i <= k) {
            ans = min(ans, 1 + findAns(k - i));
        }
    }
    return dp[k] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << findAns(n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}