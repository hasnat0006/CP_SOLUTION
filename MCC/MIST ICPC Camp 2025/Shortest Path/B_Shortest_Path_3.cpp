
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, ll> pairi;
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> A(n + 1);
    vector<array<int, 2>> adj[n + 5];
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dis(n + 5, inf), vis(n + 5, 0);

    auto dijkstra = [&](ll src) {
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<>> pq;
        dis[src] = 0;
        pq.push({0, src});
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            if(vis[top[1]])
                continue;
            vis[top[1]] = 1;
            for (auto [v, wt] : adj[top[1]]) {
                if (dis[v] > dis[top[1]] + wt + A[v]) {
                    dis[v] = dis[top[1]] + wt + A[v];
                    pq.push({dis[v], v});
                }
            }
        }
    };

    dijkstra(1);
    for(int i = 2; i <= n; i++) {
        cout << dis[i] + A[1] << ' ';
    }

    cout << '\n';
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