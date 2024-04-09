//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|04|2024 16:09:50            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

vector<int> dist;
vector<int> parent;
vector<vector<pair<int, int>>> adj;

void bellmonFord(int n, int src) {
    dist[src] = 0;
    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it.first;
                int wt = it.second;
                if (dist[u] != inf && ((dist[u] + wt) < dist[v])) {
                    if (step == n - 1) {
                        cout << "Negative cycle found" << endl;
                        return;
                    }
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == inf ? 30000 : dist[i]) << " ";
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    dist.resize(n + 1, inf);
    adj.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // cout << "---" << endl;
    for(int i = 0; i < n; i++){
        for(auto it : adj[i]){
            cout << i << " -> " << it.first << " " << it.second << endl;
        }
    }
    bellmonFord(n, 0);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}