//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|03|2024 23:16:44            !//
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

int dp[105][105];
int N, M;

int findSum(int row, int col, vector<vector<int>> &v) {
    if (row == 0)
        return v[row][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int up = -inf, leftDia = -inf, rightDia = -inf;
    up = v[row][col] + findSum(row - 1, col, v);
    auto isValid = [&](int x, int y) {
        if (x < 0 or x >= N or y < 0 or y >= M)
            return false;
        return true;
    };
    if (isValid(row - 1, col - 1))
        leftDia = v[row][col] + findSum(row - 1, col - 1, v);
    if (isValid(row - 1, col + 1))
        rightDia = v[row][col] + findSum(row - 1, col + 1, v);
    return dp[row][col] = max({up, leftDia, rightDia});
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    memset(dp, -1, sizeof(dp));
    N = matrix.size(), M = matrix[0].size();
    int ans = -inf;
    for (int i = 0; i < M; i++) {
        ans = max(ans, findSum(N - 1, i, matrix));
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cout << getMaxPathSum(v) << endl;
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