//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

map<int, vector<int>> adj;
map<int, map<int, int>> visited, level;

void reset() {
    adj.clear();
    visited.clear();
    level.clear();
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start][start] = 1;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto child : adj[k]) {
            if (!visited[start][child]) {
                q.push(child);
                level[start][child] = level[start][k] + 1;
                visited[start][child] = 1;
            }
        }
    }
}

void solve(int n, int p) {
    reset();
    int x, y, c = 1;
    while (n--) {
        cin >> x;
        adj[x].pb(c);
        adj[c].pb(x);
    }
    c++;
    int koybar = 18;
    while (koybar--) {
        int x;
        cin >> x;
        while (x--) {
            cin >> y;
            adj[y].pb(c);
            adj[c].pb(y);
        }
        c++;
    }
    int ans;
    cin >> ans;
    cout << "Test Set #" << p << endl;
    // printf("Test Set #%lld\n", p);
    if (ans > 20) {
        x = 21;
        while (x--)
            bfs(x);
        while (ans--) {
            cin >> x >> y;
            cout << setw(2) << x << " to " << setw(2) << y << ": "
                 << level[x][y] << endl;
        }
    }
    else {
        while (ans--) {
            cin >> x >> y;
            bfs(x);
            cout << setw(2) << x << " to " << setw(2) << y << ": "
                 << level[x][y] << endl;
            // printf("%2lld to %2lld: %lld\n", x, y, level[x][y]);
        }
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA;
    int c = 1;
    int n;
    int f = 0;
    while (cin >> n) {
        solve(n, c++);
    }
    return 0;
}