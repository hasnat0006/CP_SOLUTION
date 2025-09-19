#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll> pairi;
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll st, en, x, y;
    cin >> st >> en >> x >> y;
    vector<array<ll, 2>> adj[300];
    for (int a = 1; a <= 100; a++) {
        adj[a].push_back({100 + a, x});
        adj[100 + a].push_back({a, x});
        if (a != 1) {
            adj[a].push_back({a - 1, y});
            adj[a - 1].push_back({a, y});
            adj[100 + a].push_back({100 + a - 1, y});
            adj[100 + a - 1].push_back({100 + a, y});

            adj[a].push_back({100 + a - 1, x});
            adj[100 + a - 1].push_back({a, x});
        }
    }

    vector<ll> dis(300, inf);
    
    auto dijkstra = [&] (ll src) {
        priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
        dis[src] = 0;
        pq.push({0, src});
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            for (auto [v, wt] : adj[top.second]) {
                if (dis[v] > dis[top.second] + wt) {
                    dis[v] = dis[top.second] + wt;
                    pq.push({dis[v], v});
                }
            }
        }
    };

    dijkstra(st);
    cout << dis[100 + en] << '\n';
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