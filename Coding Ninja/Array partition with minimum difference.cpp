//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 02:25:21            !//
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

int dp[1005][10005];

bool findSum(int n, int k, vector<int> &v) {
    if (k == 0)
        return true;
    if (n == 0)
        return v[n] == k;
    if (dp[n][k] != -1)
        return dp[n][k];
    bool notTake = findSum(n - 1, k, v), take = false;
    if (k - v[n] >= 0)
        take = findSum(n - 1, k - v[n], v);
    dp[n][k] = take | notTake;
    return dp[n][k];
}

int canPartition(vector<int> &arr, int n) {
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(arr.begin(), arr.end(), 0ll);
    int ans = inf;
    for (int j = 0; j <= (sum + 1) / 2; j++) {
        if (findSum(n - 1, j, arr) == true) {
                ans = min(ans, abs((sum - j) - j));
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << (canPartition(v, n)) << endl;
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