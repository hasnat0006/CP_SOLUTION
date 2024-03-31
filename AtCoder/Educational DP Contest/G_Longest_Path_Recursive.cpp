//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|03|2024 02:24:11            !//
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

int n, m;
int dp[100005];
vector<int> adj[100005];

int findDistance(int node) {
    if (dp[node] != -1)
        return dp[node];
    int ans = 0;
    for (auto i : adj[node]) {
        ans = max(ans, 1 + findDistance(i));
    }
    return dp[node] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        findDistance(i);
    }
    cout << *max_element(dp, dp + 100005) << endl;
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