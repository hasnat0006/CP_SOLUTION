//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int dp[N][N], mark[N][N];

int LCS(int i, int j, vector<int> a, vector<int> b) {
    if (i == 0 or j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // if matched.
    if (a[i - 1] == b[j - 1]) {
        mark[i][j] = 1;  //! 1 for diagonal
        return dp[i][j] = LCS(i - 1, j - 1, a, b) + 1;
    }
    else {
        int left = LCS(i - 1, j, a, b);
        int right = LCS(i, j - 1, a, b);
        if (left > right) {
            mark[i][j] = 2;  //! 2 for up
        }
        else
            mark[i][j] = 3;  //! 3 for right
        return dp[i][j] = max(left, right);
    }
}

void print_lcs(int i, int j, vector<int> a, vector<int> b) {
    if (i == 0 or j == 0)
        return;
    if (mark[i][j] == 1) {
        print_lcs(i - 1, j - 1, a, b);
        cout << a[i - 1] << " ";
    }
    else if (mark[i][j] == 2)
        print_lcs(i - 1, j, a, b);
    else if (mark[i][j] == 3)
        print_lcs(i, j - 1, a, b);
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    LCS(n, m, a, b);
    print_lcs(n, m, a, b);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}