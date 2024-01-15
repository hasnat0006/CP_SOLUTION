//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

// vector<vector<pair<int,int>>> edges
// u {v, wt}
void bellmonFord(int n, int m, int src, vector<vector<pair<int, int>>> &edges) {
    vector<int> dist(n + 1, 30000);
    dist[src] = 0;
    for (int step = 0; step < n; step++) {
        for (int i = 1; i <= n; i++) {
            for (auto it : edges[i]) {
                int u = i;
                int v = it.first;
                int wt = it.second;
                if (dist[u] != 30000 && ((dist[u] + wt) < dist[v])) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << endl;
}

void solve() {
    int n, m, u, v, wt;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    bellmonFord(n, m, 1, adj);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}