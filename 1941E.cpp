//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 22:32:50            !//
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

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> ans(n, inf);
    for (int i = 0; i < n; i++) {
        vector<int> dp(m, 0);
        multiset<int> st;
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                dp[j] = 1;
                st.insert(dp[j]);
            }
            else {
                int mn = *st.begin();
                dp[j] = v[i][j] + 1 + mn;
                if (st.size() == d + 1) {
                    // dbg("--");
                    st.erase(st.find(dp[j - d - 1]));
                }
                st.insert(dp[j]);
            }
        }
        ans[i] = dp.back();
    }
    int cost = inf, tempCost = 0;
    for (int i = 0; i < k; i++) {
        tempCost += ans[i];
    }
    cost = min(cost, tempCost);
    for (int i = k; i < n; i++) {
        tempCost -= ans[i - k];
        tempCost += ans[i];
        cost = min(cost, tempCost);
    }
    cout << cost << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}