//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|04|2024 00:28:48            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

typedef pair<int, pair<int, int>> pairUV;
typedef pair<int, int> pairi;
vector<vector<pairi>> adj2;
vector<int> dis;

void dijkstra(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj2[top.second]) {
            int v = i.first;
            int wt = i.second;
            if (dis[v] > dis[top.second] + wt) {
                dis[v] = dis[top.second] + wt;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int sum = 0;
    priority_queue<pairUV, vector<pairUV>, greater<pairUV>> pq;
    vector<bool> visited(n + 1, 0);
    vector<pairUV> ans;
    pq.push({0, {1, -1}});
    while (!pq.empty()) {
        pairUV k = pq.top();
        pq.pop();
        int u = k.second.first;
        int v = k.second.second;
        int wt = k.first;
        if (visited[u])
            continue;
        if (v != -1)
            ans.push_back({wt, {u, v}});
        sum += wt;
        visited[u] = 1;
        for (auto it : adj[u]) {
            int adjNode = it.first;
            int adjwt = it.second;
            if (!visited[adjNode])
                pq.push({adjwt, {adjNode, u}});
        }
    }
    adj2.clear();
    adj2.resize(n + 1);
    dis.clear();
    dis.resize(n + 1, inf);
    for (auto it : ans) {
        int u = it.second.first;
        int v = it.second.second;
        int wt = it.first;
        adj2[u].push_back({v, wt});
        adj2[v].push_back({u, wt});
    }
    dijkstra(1);
    cout << dis[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}