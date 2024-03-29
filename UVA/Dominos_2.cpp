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
vector<int> visited;
void dfs(int start, vector<int> adj[]) {
    visited[start] = 1;
    for (auto child : adj[start]) {
        if (!visited[child])
            dfs(child, adj);
    }
}

void solve() {
    visited.resize(10005, 0);
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> v(n + 1);
    vector<int> adj[10005];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    while (l--) {
        int start;
        cin >> start;
        if (!visited[start])
            dfs(start, adj);
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << "->" << visited[i] << endl;
        if (visited[i])
            c++;
    }
    cout << c << endl;
    visited.clear();
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}