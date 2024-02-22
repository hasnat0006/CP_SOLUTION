//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int cnt = 0;
int dp[100005];
int n;
int findAns(int sum) {
    if (dp[sum] != -1) {
        return dp[sum];
    }
    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        if (sum - i >= 0)
            cnt += findAns(sum - i) + 1;
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    // findAns(0);
    cout << findAns(n) << endl;
    for (int i = 0; i <= n; i++) {
        cout << dp[i] << " ";
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}