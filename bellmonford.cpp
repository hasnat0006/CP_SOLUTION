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

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for negative cycle

    bool f = true;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] + wt < dist[v]) {
            f = false;
            break;
        }
    }

    if (f)
        return dist;
}

void solve() {
    int n, m, u, v, wt;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> wt;
        v[i].pb()
    }
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