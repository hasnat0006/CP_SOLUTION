//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int n;
map<pair<int, int>, int> block, visited;
vector<pair<int, int>> XY = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValid(int x, int y) {
    if (visited[{x, y}] >= 1)
        return false;
    if (x <= 0 or y <= 0)
        return false;
    if (x > n or y > n)
        return false;
    if (block[{x, y}] == 1)
        return false;
    return true;
}

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[{i, j}] = 1;
    while (!q.empty()) {
        auto k = q.front();
        q.pop();
        for (auto child : XY) {
            int x = k.first + child.first;
            int y = k.second + child.second;
            if (block[{x, y}] == 0 and visited[{x, y}] == 0 and x >= 1 and
                y >= 1 and x <= n and y <= n) {
                q.push({x, y});
                visited[{x, y}] = 1;
            }
        }
    }
}

void solve() {
    int m;
    block.clear();
    visited.clear();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        block[{u, v}] = 1;
    }
    bfs(1, 1);
    if (visited[{n, n}] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}