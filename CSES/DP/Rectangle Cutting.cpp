//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|04|2024 13:31:03            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

int dp[505][505];

int minimumCut(int n, int m){
    if(n == m)
        return 0;
    if(n == 1)
        return m - 1;
    if(m == 1)
        return n - 1;
    // memoization
    if(dp[n][m] != -1)
        return dp[n][m];
    int ans = inf;
    // vertical cuts
    for(int i = 1; i < m; i++){
        int temp = minimumCut(n, i) + minimumCut(n, m - i) + 1;
        ans = min(ans, temp);
    }
    // horizontal cuts
    for(int i = 1; i < n; i++){
        int temp = minimumCut(i, m) + minimumCut(n - i, m) + 1;
        ans = min(ans, temp);
    }
    return dp[n][m] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    cout << minimumCut(n, m) << endl;
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