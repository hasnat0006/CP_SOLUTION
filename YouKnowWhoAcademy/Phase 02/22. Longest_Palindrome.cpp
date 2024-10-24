//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 00:53:01            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

string a, b;
int dp[1005][1005];

ll LCS(int i, int j) {
    if (i == -1 or j == -1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans;
    if (a[i] == b[j])
        ans = 1 + LCS(i - 1, j - 1);
    else
        ans = max(LCS(i - 1, j), LCS(i, j - 1));
    return dp[i][j] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    getline(cin, a);
    b = a;
    reverse(vf(b));
    cout << LCS(a.size() - 1, b.size() - 1) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}