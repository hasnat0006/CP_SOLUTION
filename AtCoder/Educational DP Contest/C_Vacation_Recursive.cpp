//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 21:23:02            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

vector<vector<int>> v(100005, vector<int>(3));
int dp[100005][3];

int findAns(int i, int last) {
    if (i < 0)
        return 0;
    if (dp[i][last] != -1)
        return dp[i][last];
    int mx = 0;
    for (int k = 0; k < 3; k++) {
        if (k != last) {
            mx = max(mx, v[i][k] + findAns(i - 1, k));
        }
    }
    return dp[i][last] = mx;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    cout << findAns(n - 1, 3) << endl;
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