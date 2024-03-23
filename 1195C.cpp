//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|03|2024 02:48:21            !//
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

vector<vector<int>> v(100005, vector<int>(2));
vector<vector<int>> dp(100005, vector<int>(2, -1));

int findMaxHeight(int id, int k){
    if(id == 0){
        if(k == 0)
            return v[0][0];
        else
            return v[0][1];
    }
    if(dp[id][k] != -1)
        return dp[id][k];
    if(k == 0){
        dp[id][k] = max(findMaxHeight(id - 1, 1) + v[id][0], findMaxHeight(id - 1, 0));
    }
    else{
        dp[id][k] = max(findMaxHeight(id - 1, 0) + v[id][1], findMaxHeight(id - 1, 1));
    }
    return dp[id][k];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[j][i];
        }
    }
    cout << max(findMaxHeight(n - 1, 0), findMaxHeight(n - 1, 1)) << endl;
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