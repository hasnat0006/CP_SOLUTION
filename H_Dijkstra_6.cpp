//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|05|2024 10:59:05            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve(int n, int m) {
    int s, e;
    cin >> s >> e;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> dis(n + 1, inf);
    vector<int> par(n + 1, -1);
    auto dijkstra = [&](int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[src] = 0;
        pq.push({0, src});
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            if (top.first != dis[top.second])
                continue;
            for (auto i : adj[top.second]) {
                int v = i.first;
                int wt = i.second;
                if (dis[v] > dis[top.second] + wt) {
                    dis[v] = dis[top.second] + wt;
                    par[v] = top.second;
                    pq.push({dis[v], v});
                }
            }
        }
    };
    dijkstra(s);
    if (dis[e] == inf) {
        cout << -1 << endl;
        return;
    }
    int smallest = dis[e], secondS = dis[e];
    while (smallest == secondS) {
        dbg(smallest);
        vector<int> path;
        for (int i = e; i != -1; i = par[i])
            path.push_back(i);
        reverse(vf(path));
        dbg(path);
        for (int i = 1; i < path.size(); i++) {
            int u = path[i - 1], v = path[i];
            for (auto &j : adj[u]) {
                if (j.first == v) {
                    j.second = inf;
                    break;
                }
            }
            fill(vf(dis), inf);
            dijkstra(s);
            if (dis[e] == inf) {
                cout << -1 << endl;
                return;
            }
            secondS = dis[e];
        }
    }
    cout << secondS << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 and m == 0)
            break;
        else
            solve(n, m);
    }
    return 0;
}