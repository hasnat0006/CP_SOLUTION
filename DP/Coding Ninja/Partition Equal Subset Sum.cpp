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

int dp[500][10005];

bool findSum(int n, int k, vector<int> &v) {
    if (k == 0)
        return true;
    if (n == -1)
        return false;
    if (dp[n][k] != -1)
        return dp[n][k];
    bool notTake = findSum(n - 1, k, v), take = false;
    if (k - v[n] >= 0)
        take = findSum(n - 1, k - v[n], v);
    return dp[n][k] = take | notTake;
}

bool canPartition(vector<int> &arr, int n) {
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(arr.begin(), arr.end(), 0ll);
    if(sum % 2)
        return false;
    return findSum(n - 1, sum / 2, arr);
}

void solve() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << (canPartition(v, n) ? "true" : "false") << endl;
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