//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 02:14:47            !//
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

int dp[1005][1005];

int KNAPSACK(int id, int wt, vector<int> &profit, vector<int> &weight) {
    if (wt == 0)
        return 0;
    if (id < 0)
        return 0;
    if (dp[id][wt] != -1)
        return dp[id][wt];
    int notTake = KNAPSACK(id - 1, wt, profit, weight), take = 0;
    if (wt - weight[id] >= 0)
        take = profit[id] + KNAPSACK(id, wt - weight[id], profit, weight);
    return dp[id][wt] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    memset(dp, -1, sizeof(dp));
    return KNAPSACK(n - 1, w, profit, weight);
}

void solve() {
    int n;
    cin >> n;
    vector<int> w(n), profit(n);
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        w[i] = i + 1;
    cout << unboundedKnapsack(n, n, profit, w) << endl;
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