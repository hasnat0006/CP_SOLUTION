//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 22:51:56            !//
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

int n, m, k;
vector<pair<int, int>> XY = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[900][900];
int dist[900][900];
char grid[900][900];

bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void dfs(int x, int y, int a, int b) {
    if (a < 0 || b < 0)
        return;
    for (auto i : XY) {
        int nx = x + i.first;
        int ny = y + i.second;
        if (check(nx, ny) && !vis[nx][ny]) {
            if (grid[nx][ny] == '#')
                b--;
            else
                a--;
            vis[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            dfs(nx, ny, a, b);
            vis[nx][ny] = 0;
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    pair<int, int> start;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                start = {i, j};
        }
    }
    int x = start.first, y = start.second;
    vis[x][y] = 1;
    dfs(x, y, k, k);
    int ans = inf;
    // left col
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[i][1]);
    }
    // right col
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[i][m]);
    }
    // top row
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dist[1][i]);
    }
    // bottom row
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dist[n][i]);
    }
    cout << ans << endl;
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