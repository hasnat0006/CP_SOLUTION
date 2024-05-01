//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|05|2024 16:23:55            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int n;
vector<int> a;
int dp[300005][12];

int DP(int i, int k) {
    if (i == n)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int mn = inf, ans = inf;
    for (int j = 0; j <= k and i + j < n; j++) {
        mn = min(mn, a[i + j]);
        ans = min(ans, mn * (j + 1) + DP(i + j + 1, k - j));
    }
    return dp[i][k] = ans;
}

void solve() {
    int k;
    cin >> n >> k;
    a.clear();
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = -1;
    cout << DP(0, k) << endl;
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