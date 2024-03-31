//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 02:51:12            !//
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

vector<int> v;
int dp[105][1000005];
int SUM(int id, int k) {
    if (k == 0)
        return 1;
    if (id < 0)
        return 0;
    if(dp[id][k] != -1)
        return dp[id][k];
    int notTake = SUM(id - 1, k), take = 0;
    if(k - v[id] >= 0)
        take = SUM(id, k - v[id]);
    // dbg(id, k, take, notTake);
    return dp[id][k] = (take + notTake) % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << SUM(n - 1, k) << endl;
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