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
    ll n, m;
    cin >> n >> m;
    vector<ll> battery(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> battery[i];

    vector<vector<pairi>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    auto dijkstra = [&](ll cost) {
        vector<ll> dis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (dis[i] == 0 && i > 1)
                continue;
            dis[i] += battery[i];
            dis[i] = min(dis[i], cost);
            for (auto [v, w] : adj[i]) {
                if (dis[i] >= w)
                    dis[v] = max(dis[v], dis[i]);
            }
        }

        return dis[n] > 0;
    };

    ll l = 0, r = inf;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (dijkstra(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << (l == inf ? -1 : l) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}