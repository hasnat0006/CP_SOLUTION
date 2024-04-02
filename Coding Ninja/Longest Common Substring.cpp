//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|04|2024 15:46:41            !//
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

int dp[1005][1005], mark[1005][1005];
string A, B, LCS = "";

int ans(int i, int j) {
    if (i == 0 or j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (A[i - 1] == B[j - 1]) {
        mark[i][j] = 1;
        return dp[i][j] = 1 + ans(i - 1, j - 1);
    }
    int up = ans(i - 1, j), down = ans(i, j - 1);
    mark[i][j] = (up > down) ? 2 : 3;
    return dp[i][j] = max(up, down);
}

void findLCS(int i, int j) {
    if (i == 0 or j == 0)
        return;
    if (mark[i][j] == 1)
        findLCS(i - 1, j - 1), LCS.push_back(A[i - 1]);
    if (mark[i][j] == 2)
        findLCS(i - 1, j);
    else if (mark[i][j] == 3)
        findLCS(i, j - 1);
}

int lcs(string s, string t) {
    memset(dp, -1, sizeof(dp));
    memset(mark, 0, sizeof(mark));
    A = s, B = t;
    ans(A.size(), B.size());
    findLCS(A.size(), A.size());
    cout << LCS << endl;
}

void solve() {
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
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