//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

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

int32_t main() {
    int n, m, u, v, wt;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    bellmonFord(n, m, 1, adj);
    return 0;
}
/*
5
7
A B 2
A C 4
B C 1
B D 7
C E 3
D E 1
E A -6
A
E
*/