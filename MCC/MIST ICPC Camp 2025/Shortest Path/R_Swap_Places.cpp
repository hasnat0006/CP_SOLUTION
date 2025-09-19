// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m, x;
    cin >> n >> m;
    const ll N = n + 5;

    vector<ll> col(N);
    for (int i = 1; i <= n; i++)
        cin >> col[i];

    const ll inf = 1e18;
    vector<ll> adj[N];
    for (int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto Dijkstra = [&]() {
        queue<array<ll, 2>> pq;
        pq.push({1, n});
        vector<vector<ll>> dis(n + 5, vector<ll>(n + 5, -1));
        dis[1][n] = 0;
        while (!pq.empty()) {
            auto [u, v] = pq.front();
            pq.pop();
            for (auto uu : adj[u]) {
                for (auto vv : adj[v]) {
                    if (col[uu] != col[vv]) {
                        if (dis[uu][vv] == -1) {
                            dis[uu][vv] = dis[u][v] + 1;
                            pq.push({uu, vv});
                        }
                    }
                }
            }
        }
        return dis[n][1];
    };

    cout << Dijkstra() << '\n';
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}