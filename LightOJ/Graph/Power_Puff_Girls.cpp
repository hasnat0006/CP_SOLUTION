//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

// #define int long long
// #define float long double
#define pb push_back
#define pairi pair<int, int>
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1001000007;
float pi = 3.141592653589793238462643383279502884197;
// int inf = 1e18;

int n, m;
pairi ed;
vector<pairi> eid;
map<pairi, int> visited, level;
vector<pairi> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y) { return (x >= 0 and x < n and y >= 0 and y < m); }

void bfs(pairi start) {
    queue<pairi> q;
    q.push(start);
    visited[{start.first, start.second}] = 1;
    while (!q.empty()) {
        pairi k = q.front();
        q.pop();
        for (auto it : moves) {
            int x = k.first + it.first;
            int y = k.second + it.second;
            if (isValid(x, y) and !visited[{x, y}]) {
                visited[{x, y}] = 1;
                q.push({x, y});
                level[{x, y}] = level[k] + 1;
            }
        }
    }
}

void reset() { eid.clear(), level.clear(), visited.clear(); }

void solve() {
    reset();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == '#' or x == 'm')
                visited[{i, j}] = 2;
            else if (x == 'a' or x == 'b' or x == 'c')
                eid.pb({i, j});
            else if (x == 'h')
                ed = {i, j};
        }
    }
    int ans = INT_MIN;
    bfs(ed);
    for (auto it : eid) {
        ans = max(ans, level[it]);
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();
    return 0;
}