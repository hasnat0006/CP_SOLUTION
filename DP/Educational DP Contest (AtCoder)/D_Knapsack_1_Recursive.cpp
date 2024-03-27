//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 03:41:14            !//
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

int dp[105][100005];
vector<pair<int, int>> vp;

int KNAPSACK(int id, int wt) {
    if (id == -1)
        return 0;
    if (dp[id][wt] != -1)
        return dp[id][wt];
    int nibo = 0, niboNa = KNAPSACK(id - 1, wt);
    if (wt >= vp[id].second)
        nibo = vp[id].first + KNAPSACK(id - 1, wt - vp[id].second);
    return dp[id][wt] = max(nibo, niboNa);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    vp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vp[i].second >> vp[i].first;
    cout << KNAPSACK(n - 1, w) << endl;
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