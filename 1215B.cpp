//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|03|2024 02:15:39            !//
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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0][0] = (v[0] > 0) ? 1 : 0;
    dp[0][1] = (v[0] < 0) ? 1 : 0;
    for(int i = 1; i < n; i++){
        if(v[i] > 0){
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
        else{
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = 1 + dp[i - 1][0];
        }
    }
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++)
        pos += dp[i][0], neg += dp[i][1];
    cout << neg << " " << pos << endl;
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