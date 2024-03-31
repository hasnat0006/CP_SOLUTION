//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 01:08:24            !//
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

int dp[20][10005];

int findAns(int id, int k, vector<int> &v) {
    if (k == 0)
        return 0;
    if (id < 0)
        return INT_MAX;
    if (dp[id][k] != -1)
        return dp[id][k];
    int notPick = findAns(id - 1, k, v), pick = INT_MAX;
    if (k - v[id] >= 0)
        pick = 1 + findAns(id, k - v[id], v);
    return dp[id][k] = min(pick, notPick);
}

int minimumElements(vector<int> &num, int k) {
    memset(dp, -1, sizeof(dp));
    int x = findAns(num.size() - 1, k, num);
    return (x == INT_MAX ? -1 : x);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << minimumElements(v, k) << endl;
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