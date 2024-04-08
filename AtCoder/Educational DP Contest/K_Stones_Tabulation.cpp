//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 00:53:24            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int dp[k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int stone = v.front(); stone <= k; stone++) {
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (stone >= v[i]) {
                ans = ans | !dp[stone - v[i]][1];
            }
        }
        dp[stone][0] = ans;
        ans = false;
        for (int i = 0; i < v.size(); i++) {
            if (stone >= v[i]) {
                ans = ans | !dp[stone - v[i]][0];
            }
        }
        dp[stone][1] = ans;
    }
    cout << (dp[k][0] ? "First" : "Second") << endl;
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