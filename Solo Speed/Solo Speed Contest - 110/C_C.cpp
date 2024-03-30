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
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

map<int, vector<int>> adj;
int c = 0;
map<int, int> visited;

void dfs(int start) {
    visited[start] = 1;
    for (auto child : adj[start]) {
        if (!visited[child]) {
            c++;
            dfs(child);
        }
    }
}

void solve() {
    int n, m, x, y, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
        dfs(i), ans += c, c = 0, visited.clear();
    cout << ans + n << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}