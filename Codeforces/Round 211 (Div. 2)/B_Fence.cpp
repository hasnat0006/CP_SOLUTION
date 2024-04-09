//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|04|2024 01:47:15            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(n, inf);
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += v[i];
    dp[k - 1] = sum;
    for (int i = k; i < n; i++) {
        sum += v[i] - v[i - k];
        dp[i] = sum;
    }
    int mn = *min_element(vf(dp));
    for (int i = 0; i < n; i++) {
        if (dp[i] == mn) {
            cout << i + 2 - k << endl;
            return;
        }
    }
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