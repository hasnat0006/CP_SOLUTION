//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|04|2024 01:14:04            !//
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

vector<int> v;
set<int> ans;

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> dp(n * 1001);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int coin = (n * 1001) - 1; coin > 0; coin--) {
            if (coin - v[i] >= 0 and dp[coin - v[i]])
                dp[coin] = 1;
        }
    }
    for (int i = 1; i < n * 1001; i++)
        if (dp[i])
            ans.insert(i);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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