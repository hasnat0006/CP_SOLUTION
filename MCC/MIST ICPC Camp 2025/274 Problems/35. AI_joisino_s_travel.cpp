#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

typedef pair<ll, ll> pairi;
const ll N = 200 + 5;
vector<pairi> adj[N];
vector<ll> dis(N, inf), parent(N);

void dijkstra(ll src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            ll v = i.first;
            ll wt = i.second;
            if (dis[v] > dis[top.second] + wt) {
                dis[v] = dis[top.second] + wt;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve() {
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> v(r);
    for (int i = 0; i < r; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(v.front());

    dbg(dis);
    ll ans = 0;
    for(auto i : v) 
        ans = max(ans, dis[i]);
    cout << ans << '\n';
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