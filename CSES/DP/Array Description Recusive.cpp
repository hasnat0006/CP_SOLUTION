//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 21:20:01            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1000000007;
#define inf 1000000000000000000;

int n, m;
vector<int> v;
vector<vector<int>> dp(100005, vector<int>(101 + 1, -1));

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

bool valid(int x) { return (x > 0 and x <= m); }

int findAns(int i, int j) {
    if (i == 0) {
        if (v[i] == 0 or v[i] == j)
            return 1;
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    for (int k = j - 1; k <= j + 1; k++) {
        if (v[i] != 0 and v[i] != j)
            continue;
        if (valid(k)) {
            ans = mod_add(ans, findAns(i - 1, k));
        }
    }
    return dp[i][j] = ans;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    int ans = 0;
    for (int i = 1; i <= m; i++) 
        ans = mod_add(ans, findAns(n - 1, i));
    cout << ans << endl;
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