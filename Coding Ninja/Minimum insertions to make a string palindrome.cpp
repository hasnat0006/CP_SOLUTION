//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 15:05:14            !//
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

vector<vector<int>> dp(1005, vector<int>(1005, -1));

int lcs(int i, int j, string &a, string &b) {
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b);
    return dp[i][j] = max(lcs(i - 1, j, a, b), lcs(i, j - 1, a, b));
}

int minimumInsertions(string &str) {
    string t = str;
    reverse(t.begin(), t.end());
    return str.length() - lcs(str.length() - 1, t.length() - 1, str, t);
}

void solve() {
    string s;
    cin >> s;
    cout << minimumInsertions(s) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}