//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 01:46:50            !//
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


long dp[15][2005];
long findAns(int id, int k, int *v) {
    if(id == 0)
        return (k % v[id] == 0);
    if(dp[id][k] != -1)
        return dp[id][k];
    long notTake = findAns(id - 1, k, v), take = 0;
    if (k - v[id] >= 0)
        take = findAns(id, k - v[id], v);
    return dp[id][k] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    memset(dp, -1, sizeof(dp));
    return findAns(n - 1, value, denominations);
}

void solve() {
    int n;
    cin >> n;
    int *v = new int[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    int k;
    cin >> k;
    cout << countWaysToMakeChange(v, n, k);
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