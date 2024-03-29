//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

map<int, vector<int>> adj;
map<int, int> visited;
map<int, int> level;
map<int, int> parent;
int c = 1;
void reset() {
    adj.clear();
    visited.clear();
    level.clear();
}

int bfs(int start, int lv) {
    queue<int> q;
    int c = 0;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto child : adj[k]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = 1;
                level[child] = level[k] + 1;
                if (level[child] <= lv)
                    c++;
            }
        }
    }
    return c;
}

void solve(int n) {
    reset();
    int x, y;
    while (n--) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    while (cin >> x >> y) {
        if (!x and !y)
            break;
        if (adj.find(x) == adj.end()) {
            cout << "Case " << c++ << ": " << adj.size()
                 << " nodes not reachable from node " << x
                 << " with TTL = " << y << "." << endl;
        }
        else {
            cout << "Case " << c++ << ": " << adj.size() - bfs(x, y) - 1
                 << " nodes not reachable from node " << x
                 << " with TTL = " << y << "." << endl;
            // debug(level);
            level.clear();
            visited.clear();
        }
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    while (cin >> t) {
        if (!t)
            break;
        solve(t);
    }
    return 0;
}