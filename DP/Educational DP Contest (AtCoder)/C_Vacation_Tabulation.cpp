//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 15:35:53            !//
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
    int arr[n][3], dp[n][3];
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0)
                dp[i][j] = arr[i][j] + max(dp[i - 1][1], dp[i - 1][2]);
            else if (j == 1)
                dp[i][j] = arr[i][j] + max(dp[i - 1][0], dp[i - 1][2]);
            else
                dp[i][j] = arr[i][j] + max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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
