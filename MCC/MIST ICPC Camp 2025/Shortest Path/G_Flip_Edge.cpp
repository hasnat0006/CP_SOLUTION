// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 10;
const ll inf = 1e18;
ll n, m, x;
vector<pair<ll, ll>> adj[2][N];

ll Dijkstra(ll src) {
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
    pq.push({0, src, 0});
    vector<vector<ll>> dis(N, vector<ll>(2, inf)), vis(N, vector<ll>(2, 0));
    dis[1][0] = 0;
    while (!pq.empty()) {
        auto [d, u, flip] = pq.top();
        pq.pop();
        if (vis[u][flip])
            continue;
        vis[u][flip] = 1;
        for (auto [v, w] : adj[flip][u]) {
            if (d + w < dis[v][flip]) {
                dis[v][flip] = d + w;
                pq.push({dis[v][flip], v, flip});
            }
        }
        pq.push({d + x, u, !flip});
    }
    return min(dis[n][1], dis[n][0]);
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[0][u].push_back({v, 1});
        adj[1][v].push_back({u, 1});
    }

    cout << Dijkstra(1) << '\n';
}