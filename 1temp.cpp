//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 14:28:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

int mod = 1000000007;
int inf = 1e18;

int N, M;
vector<pair<int, int>> grid = {{0, 1}, {1, 0}};

bool visited[100][100];
bool isValid(int x, int y) {
    if (visited[x][y] == 1)
        return false;
    if (x <= N and x > 0 and y <= M and y > 0)
        return true;
    return false;
}

void Print() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int findWay(int x, int y, vector<vector<int>> &dp) {
    if (x == N and y == M) {
        return dp[x][y] = 1;
    }
    if (dp[x][y] != 0)
        return dp[x][y];
    int total = 0;
    Print();
    for (auto i : grid) {
        int X = x + i.first;
        int Y = y + i.second;
        // dbg(x, y, X, Y);
        if (isValid(X, Y)) {
            visited[X][Y] = 1;
            // dbg(X, Y);
            total += findWay(X, Y, dp);
            visited[X][Y] = 0;
        }
    }
    return dp[x][y] = total;
}

void solve() {
    memset(visited, 0, sizeof(visited));
    int n, m;
    cin >> n >> m;
    N = n, M = m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    cout << findWay(1, 1, dp) << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
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