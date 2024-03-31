//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 00:30:17            !//
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

vector<int> Y = {-1, 0, 1};
int dp[55][55][55];

int findSum(int row, int col1, int col2, vector<vector<int>> &v) {
    if (col1 < 0 or col1 >= v[0].size() or col2 < 0 or col2 >= v[0].size())
        return -inf;
    if (row == v.size() - 1) {
        return (col1 == col2) ? v[row][col1] : v[row][col1] + v[row][col2];
    }
    if(dp[row][col1][col2] != -1)
        return dp[row][col1][col2];
    int ans = -inf;
    for(auto alice : Y){
        for(auto bob : Y){
            int temp = (col1 == col2) ? v[row][col1] : v[row][col1] + v[row][col2] + findSum(row + 1, col1 + alice, col2 + bob, v);
            ans = max(ans, temp);
        }
    }
    return dp[row][col1][col2] = ans;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    memset(dp, - 1, sizeof(dp));
    return findSum(0, 0, c - 1, grid);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    cout << maximumChocolates(n, m, v) << endl;
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